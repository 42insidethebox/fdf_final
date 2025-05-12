#!/bin/bash
echo "=== 🧠 FDF Valgrind Deep Test ($(date)) ==="
MAP_DIR="fdf_project/maps/test_maps"
OUTPUT_DIR="./valgrind_logs"
mkdir -p "$OUTPUT_DIR"

for map in "$MAP_DIR"/*.fdf; do
    filename=$(basename "$map" .fdf)
    echo "▶️ Running $filename.fdf"

    timeout 10s valgrind --leak-check=full --error-exitcode=42 \
        --log-file="$OUTPUT_DIR/${filename}.log" ./fdf "$map" > /dev/null 2>&1

    if [ ! -f "$OUTPUT_DIR/${filename}.log" ]; then
        echo "🕳️ Valgrind log not found — likely timeout or crash"
        continue
    fi

    if grep -q "Invalid write" "$OUTPUT_DIR/${filename}.log"; then
        echo "💥 Memory corruption in $filename.fdf"
    elif grep -q "definitely lost: 0 bytes" "$OUTPUT_DIR/${filename}.log"; then
        echo "✅ Leak-free: $filename.fdf"
    elif grep -q "definitely lost" "$OUTPUT_DIR/${filename}.log"; then
        echo "⚠️ Leaks detected in $filename.fdf"
    else
        echo "✅ OK: $filename.fdf"
    fi

    echo "--------------------------------------------"
done

