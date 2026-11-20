//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

public string *validateRegions(string *regionPaths)
{
    string *errors = ({});
    string *entryRooms = ({});
    mapping rooms = ([]);
    mapping roomRegions = ([]);
    mapping opposite = ([
        "north":"south",
        "south":"north",
        "east":"west",
        "west":"east",
        "up":"down",
        "down":"up",
        "northwest":"southeast",
        "northeast":"southwest",
        "southwest":"northeast",
        "southeast":"northwest"
    ]);
    object service = getService("region");

    foreach (string regionPath in regionPaths)
    {
        object region = load_object(regionPath);

        for (int x = 0; x < region->xDimension(); x++)
        {
            for (int y = 0; y < region->yDimension(); y++)
            {
                mapping cell = region->coordinateToMapping(x, y);
                if (mappingp(cell) && cell["is placed"])
                {
                    string path = cell["name"];
                    object room = cell["environment"];
                    if (objectp(room))
                    {
                        rooms[path] = room;
                        roomRegions[path] = regionPath;
                        if (cell["room type"] == "entry")
                        {
                            entryRooms += ({ path });
                        }
                    }
                    else
                    {
                        errors += ({ sprintf("%s has no loaded room", path) });
                    }
                }
            }
        }
    }

    foreach (string path, object room in rooms)
    {
        mapping snapshot = room->buildRoomSnapshot();
        int terrainCount = sizeof(snapshot["terrain"]) +
            sizeof(snapshot["interior"]);
        if (terrainCount != 1)
        {
            errors += ({ sprintf("%s must have one terrain or interior",
                path) });
        }
        if (!(sizeof(snapshot["features"]) + sizeof(snapshot["items"])))
        {
            errors += ({ sprintf("%s has no graphical feature or item",
                path) });
        }

        string decorator = room->decoratorType(0);
        if (!stringp(decorator))
        {
            errors += ({ sprintf("%s has no default decorator", path) });
        }
        else
        {
            foreach (string charset in ({ "ascii", "unicode" }))
            {
                string **icon = service->getMapIcon(
                    load_object(roomRegions[path]), decorator, "none",
                    charset);
                string rendered = implode(icon[0], "") +
                    implode(icon[1], "") + implode(icon[2], "");
                if (rendered == "         ")
                {
                    errors += ({ sprintf("%s decorator '%s' is blank in %s",
                        path, decorator, charset) });
                }
            }
        }

        mapping exits = room->getExitDirections()["default"];
        if (mappingp(exits))
        {
            foreach (string direction, string target in exits)
            {
                if (member(rooms, target))
                {
                    mapping targetExits =
                        rooms[target]->getExitDirections()["default"];
                    if (!mappingp(targetExits) ||
                        !member(opposite, direction) ||
                        !member(targetExits, opposite[direction]) ||
                        targetExits[opposite[direction]] != path)
                    {
                        errors += ({ sprintf(
                            "%s exit %s to %s is not reciprocal",
                            path, direction, target) });
                    }
                }
                else
                {
                    object targetRoom;
                    mixed loadError = catch (
                        targetRoom = load_object(target); nolog);
                    if (loadError || !objectp(targetRoom))
                    {
                        errors += ({ sprintf(
                            "%s exit %s has missing target %s",
                            path, direction, target) });
                    }
                }
            }
        }
    }

    mapping visited = ([]);
    string *pending = entryRooms + ({});
    while (sizeof(pending))
    {
        string path = pending[0];
        pending = pending[1..];
        if (!member(visited, path))
        {
            visited[path] = 1;
            mapping exits = rooms[path]->getExitDirections()["default"];
            if (mappingp(exits))
            {
                foreach (string target in m_values(exits))
                {
                    if (member(rooms, target) && !member(visited, target))
                    {
                        pending += ({ target });
                    }
                }
            }
        }
    }

    if (!sizeof(entryRooms))
    {
        errors += ({ "No registered region has an entry room" });
    }
    foreach (string path in m_indices(rooms))
    {
        if (!member(visited, path))
        {
            errors += ({ sprintf("%s is unreachable from all entries", path) });
        }
    }

    return errors;
}
