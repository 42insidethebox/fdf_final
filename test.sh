#!/bin/bash
# =========================================================
# 🧪 FDF Automated Map Tester
# Author: procha-r
# =========================================================

echo "=== 🚀 FDF Test Report: $(date) ==="
echo ""

for map in maps/test_maps/*.fdf; do
    echo "▶️ Running $map"
    timeout 0.5s ./fdf "$map" > result.log 2>&1

    if grep -q "Error" result.log; then
        echo "❌ Error detected in $map"
    elif grep -q "corruption" result.log || grep -q "invalid next size" result.log; then
        echo "💥 Memory corruption detected in $map"
    else
        echo "✅ OK: $map"
    fi

    echo "-----------------------------------"
done

echo ""
echo "=== 🏁 End of Test Report ==="
