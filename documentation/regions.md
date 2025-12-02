##### Regions

This document explains how the region subsystem works and how creators build regions.
It complements `environments.md` by focusing on region composition, auto-generation,
manual region files, mapping/decorator usage, persistence, and the public API provided
by `/lib/environment/region.c` and its submodules.

Files studied
- `lib/environment/region.c`
- `lib/environment/modules/regions/core.c`
- `lib/environment/modules/regions/*.c` (generate-*, building-*, entries-and-exits, domain, map, persist)
- `lib/environment/modules/regions/*.h` (building-parameters, room-types, display-characters)
- Example manual region: `areas/tol-dhurath/temple-interior/region.c`

Concepts and responsibilities
- A region is a grid of coordinates (cells) each referencing an environment (room).
- Regions can be:
  - manually authored (explicit coordinates point to environment files), or
  - generated at runtime using one of several algorithms (pathing, settlement, building, tunneling).
- The region object is the controller that:
  - holds `grid`, `rooms`, `decorators`, `entry` and metadata (name/type/level/dimensions),
  - generates or loads environment instances for each placed cell,
  - exposes mapping and mini-map rendering for UIs/players,
  - persists and restores regions via the region service.

Quick start — manual region
- Create a region file that inherits `/lib/environment/region.c` and implements `public void Setup()`.
- In `Setup()` set the region metadata and call `setCoordinate` / `setEntryCoordinate` / `setExitCoordinate` for each room.

Example (manual region):
\`\`\`
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Tol-Dhurath Temple, Main Level");
    setRegionType("tol-dhurath");
    setDimensions(20, 10);

    setCoordinate(0, 0, "/areas/tol-dhurath/temple-interior/0x0.c", "none");
    setCoordinate(0, 1, "/areas/tol-dhurath/temple-interior/0x1.c", "none");
    // ... more coordinates ...
}
\`\`\`

Key public region API
- `setRegionName(string)` — set human-readable name.
- `setRegionType(string)` — validated against the region service; chooses generation templates/decorators.
- `setRegionLevel(int)` — optional level metadata (used by generation/services).
- `setDimensions(int x, int y)` — set grid size (min/max enforced; default max 25x25).
  - By default the minimum allowed (when auto-generating) is 5x5. Call `asManualRegion()` to bypass that minimum.
- `asManualRegion()` — mark the region as manual; allows smaller dimensions and manual placement.
- `setCoordinate(int x, int y, string path, string roomType)` — place an explicit environment at grid cell.
- `setEntryCoordinate(int x, int y, string path, string enterFrom, string entryPoint)` — place and mark entry.
- `setExitCoordinate(int x, int y, string path, string exitTo)` — place an explicit exit cell.
- `createRegion(string enterFrom, string location, int *coordinates)` — generate (or load) region; returns entry direction.
- `createRegionFromTemplate(mapping data, object connectedRegion)` — instantiate region from published template data.
- `generateStaticFiles(string rootPath, int useRootPath)` — write out `region.c` and per-room `.c` files for a static region.
- `persistRegion()` / `setPersistRegion(int)` — control persistence behavior; `save()` calls the RegionService.

Auto-generation families
- Standard region generation (path + room placement + optional settlement):
  - Uses `generate-region.c` + `generate-path.c` + `generate-room.c` and `generate-settlement.c`.
  - Good for outdoor, wilderness, and settlement-style regions.
- Building regions (interiors like temples, keeps, ruins):
  - Controlled by `generate-building.c`, which uses building parameter templates in `building-parameters.h`.
  - BSP-style layout, walls/doors, room grouping and decorative icon selection.
  - Can fall back to a tunneling algorithm for cave/crypt/dungeon types.
- Tunneling algorithm:
  - Implemented in `generate-tunneling.c` (used for cave-like regions).
  - Carves tunnels, rooms, connects isolated sections, and marks special rooms.

Templates and parameters
- `building-parameters.h` defines parameters per building-type:
  - dimensions ranges, room types, base type, complexity, special rooms, courtyard flags.
- Room types are in `building-room-types.h` and map numeric layout values to a name and icon strategy.
- For building regions `generateBuildingTemplate()` returns:
  - `layout`, `roomIds`, `doorData`, `dimensions`, `room types` and `base type`. The generator uses these to populate `grid`.

Map & decorators
- Regions render ASCII/Unicode maps via `map.c`. Creator-facing points:
  - Add decorators to environments using `addDecorator("decorator name", "optional state")`.
  - RegionService supplies the icon data and color templates. Decorators support multiple color depths and charsets (ASCII/unicode).
  - The map renderer composes 3x3 icon tiles per cell and overlays exits and the player location. Environments may provide `customIcon()` to override default icons.
  - Use `RegionService->getMapIcon(region, decoratorType, colorConfiguration, charset)` to explore icons programmatically.

Entry, exits and connections
- Regions track `entry` coordinates and `EnterFrom` / `EntryPoint` metadata.
- The `createRegion` flow:
  - attempts to load a persisted region via `load(enterFrom, location)`.
  - if not found, generates the region (building or standard), then calls `generateRoomDetails(room)` which instantiates per-room `generatedEnvironment` objects and calls `generateEnvironment()` on them.
- `setEntryExit(string entryPoint, object region, string state)` sets up cross-region linkage so the environment at the entry cell will expose an exit to `entryPoint`.

Persistence
- `persist-region.c` handles loading/saving via the RegionService:
  - `load(enterFrom, location)` will return true when the service provides saved data; saved grid is restored and rooms are (re)generated.
  - `save()` asks `RegionService->saveRegion(this_object())`.
  - Set `PersistRegion = 0` (via `setPersistRegion(0)`) to skip persistence if desired.

Static generation (file output)
- `generateStaticFiles()` writes out `room_{$x}_{$y}.c` and `region.c` using templates and the generated layout.
- `generateRoomFile()` constructs individual room files that call `setInterior()` / `addDecorator()` and `addExit()` (or `addExitWithDoor()`).
- Use static generation to export procedural regions into author-maintainable files.

Best practices & constraints
- Grid size limits: maximum 25x25. Auto-generation enforces minimum 5x5 unless `asManualRegion()` is used.
- `setRoomCount(int)` validates a room count range computed from `MaxX`/`MaxY` to prevent poor performance or pathological layouts.
- Prefer generated templates for large, varied regions (cities, dungeons). Use manual regions when authors need fine control over each coordinate.
- When authoring a manual region, call `asManualRegion()` if you want to use small sizes or non-standard layout patterns.
- For building-type regions, tune `buildingParameters` and `roomTypes` to get the required interior look and icon mapping.
- Use `generateStaticFiles()` to produce committed region code you can later refine by hand.

Integration notes
- The region implementation relies on `RegionService` (via `getService("region")`) for:
  - validating region types,
  - providing decorator/icon data,
  - saving/loading persistent region data,
  - constructing settlement templates for populated areas.
- Environment objects placed in the grid must inherit `/lib/environment/environment.c`.
- Environments can call `setCoordinates(regionObject, x, y)` so the environment knows its region and coordinates.

Troubleshooting tips
- If `getEnvironment(coordinates)` returns 0, check bounds and whether the grid cell exists and is placed.
- If icons/characters look wrong, verify the decorator name and that `RegionService` includes that decorator for the region type.
- If generation fails, check `setRegionType(...)` and that templates exist for that type or that `RegionService->isValidRegionType()` returns true.

References & examples
- Manual region example: `areas/tol-dhurath/temple-interior/region.c`
- Building templates and parameters: `lib/environment/modules/regions/building-parameters.h`
- Map characters: `lib/environment/modules/regions/display-characters.h`
- Generation logic: `lib/environment/modules/regions/generate-*.c`
- Static generation templates: `generatedRoomTemplate.c`, `generatedRegionTemplate.c` (used by `generateStaticFiles()`)

This overview gives creators the practical knowledge to:
- author manual regions,
- choose or tune generation strategies,
- control persistence and static exports,
- customize map decorator behavior for rich visual presentation.
