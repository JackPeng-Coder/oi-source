#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""
统计当前仓库中洛谷题目的完成情况：
- 总题数、已完成、未完成（以文件名前缀 [..] 判断未完成，例如 [0]P14057.cpp）
- 按目录分类统计（如 D1-RUMEN、D2-PUJI- 等）
- 列出未完成文件清单

用法：
- 在仓库根目录运行：
  powershell> python .\stats.py
- 或指定扫描目录（默认扫描仓库根下的 LUOGU/）：
  powershell> python .\stats.py LUOGU
"""
import os
import re
import sys
from pathlib import Path
from typing import Dict, List, Tuple

UNFINISHED_PREFIX = re.compile(r"^\[[^\]]+\]")
CPP_EXT = ".cpp"


def is_unfinished(filename: str) -> bool:
    return UNFINISHED_PREFIX.match(filename) is not None


def is_cpp_file(filename: str) -> bool:
    return filename.endswith(CPP_EXT)


def collect_stats(base_dir: Path) -> Tuple[int, int, int, Dict[str, Dict[str, int]], Dict[str, List[Path]]]:
    """遍历 base_dir 下的所有 .cpp 文件，统计完成情况。

    返回：
    - total: 总题数
    - done: 已完成数量
    - undone: 未完成数量
    - per_category: 按第一层目录分类统计（category -> {total, done, undone}）
    - undone_by_category: 未完成文件映射（category -> [Path, ...]）
    """
    total, done, undone = 0, 0, 0
    per_category: Dict[str, Dict[str, int]] = {}
    undone_by_category: Dict[str, List[Path]] = {}

    for root, _, files in os.walk(base_dir):
        root_path = Path(root)
        try:
            rel = root_path.relative_to(base_dir)
            category = rel.parts[0] if rel.parts else ""
        except ValueError:
            category = ""
        if category not in per_category:
            per_category[category] = {"total": 0, "done": 0, "undone": 0}
        if category not in undone_by_category:
            undone_by_category[category] = []

        for fname in files:
            if not is_cpp_file(fname):
                continue
            total += 1
            per_category[category]["total"] += 1
            if is_unfinished(fname):
                undone += 1
                per_category[category]["undone"] += 1
                undone_by_category[category].append(root_path / fname)
            else:
                done += 1
                per_category[category]["done"] += 1

    return total, done, undone, per_category, undone_by_category


def main():
    repo_root = Path(__file__).resolve().parent
    target = Path(sys.argv[1]) if len(sys.argv) > 1 else (repo_root / "LUOGU")
    if not target.exists() or not target.is_dir():
        print(f"扫描目录不存在或不是文件夹：{target}")
        sys.exit(1)

    total, done, undone, per_cat, undone_by_cat = collect_stats(target)

    print("仓库统计（LUOGU 目录）")
    print(f"- 根路径：{target}")
    print(f"- 总题数：{total}")
    print(f"- 已完成：{done}")
    print(f"- 未完成：{undone}")
    rate = (done / total * 100) if total else 0.0
    print(f"- 完成率：{rate:.2f}%\n")

    print("按等级目录统计：")
    for category in sorted(k for k in per_cat.keys() if k):  # 排除根目录空分类
        cat_stat = per_cat[category]
        rate_c = (cat_stat["done"] / cat_stat["total"] * 100) if cat_stat["total"] else 0.0
        print(f"- {category}: 总计 {cat_stat['total']} | 已完成 {cat_stat['done']} | 未完成 {cat_stat['undone']} | 完成率 {rate_c:.2f}%")
        # 美化未完成列表
        undone_list = undone_by_cat.get(category, [])
        if undone_list:
            print("  未完成列表：")
            for p in sorted(undone_list):
                try:
                    rel_to_cat = p.relative_to(target / category)
                except ValueError:
                    rel_to_cat = p.name
                # 只显示文件名或相对分类目录路径
                display = rel_to_cat if isinstance(rel_to_cat, Path) else Path(rel_to_cat)
                print(f"    • {display}")
        print("")


if __name__ == "__main__":
    main()