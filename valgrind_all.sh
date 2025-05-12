#!/bin/bash
mkdir -p valgrind_logs

MAP_DIR="fdf_project/maps/test_maps"

for map in "$MAP_DIR"/*.fdf; do
  base=$(basename "$map")
  echo "🔍 Running Valgrind on $base"
  valgrind --leak-check=full \
           --track-origins=yes \
           --log-file="valgrind_logs/$base.log" \
           ./fdf "$map"
done

