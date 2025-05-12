#!/bin/bash

MAP_DIR="fdf_project/maps/test_maps"
OUT_DIR="valgrind_logs_deep"

mkdir -p "$OUT_DIR"

echo "🔍 Starting deep Valgrind leak inspection..."
for map in "$MAP_DIR"/*.fdf; do
    MAP_NAME=$(basename "$map")
    LOG_FILE="${OUT_DIR}/${MAP_NAME}.log"
    echo "🔬 Analyzing $MAP_NAME"
    valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --log-file="$LOG_FILE" \
             ./fdf "$map"
done

