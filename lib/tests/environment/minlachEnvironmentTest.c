//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

/////////////////////////////////////////////////////////////////////////////
void RegisteredRoomsExposeGraphicalElementsAndRenderedDecorators()
{
    mapping expectedRooms = ([
        "/areas/minlach/region.c":16,
        "/areas/minlach/surrounding/region.c":23,
        "/areas/minlach/shore/region.c":9
    ]);
    object service = getService("region");

    foreach (string path, int expected in expectedRooms)
    {
        object region = load_object(path);
        int count = 0;
        for (int x = 0; x < region->xDimension(); x++)
        {
            for (int y = 0; y < region->yDimension(); y++)
            {
                mapping cell = region->coordinateToMapping(x, y);
                if (mappingp(cell) && cell["is placed"])
                {
                    object room = cell["environment"];
                    mapping snapshot = room->buildRoomSnapshot();
                    string decorator = room->decoratorType(0);
                    ExpectTrue(stringp(decorator), cell["name"]);
                    ExpectEq(1, sizeof(snapshot["terrain"]) +
                        sizeof(snapshot["interior"]), cell["name"]);
                    ExpectTrue(sizeof(snapshot["items"]) +
                        sizeof(snapshot["features"]) > 0, cell["name"]);

                    foreach (string charset in ({ "ascii", "unicode" }))
                    {
                        foreach (string colors in ({ "none", "grayscale",
                            "3-bit", "8-bit", "24-bit" }))
                        {
                            string **icon = service->getMapIcon(region,
                                decorator, colors, charset);
                            int hasInk = 0;
                            ExpectEq(3, sizeof(icon), decorator);
                            foreach (string *row in icon)
                            {
                                ExpectEq(3, sizeof(row), decorator);
                                foreach (string section in row)
                                {
                                    hasInk ||= section != " ";
                                }
                            }
                            ExpectTrue(hasInk, decorator);
                        }
                    }

                    foreach (string type in ({ "features", "items" }))
                    {
                        foreach (mapping element in snapshot[type])
                        {
                            ExpectTrue(sizeof(element["locations"]) > 0,
                                element["element"]);
                            foreach (mapping location in element["locations"])
                            {
                                ExpectTrue(member(location, "x") &&
                                    member(location, "y") &&
                                    member(location, "z"), element["element"]);
                            }
                        }
                    }
                    count++;
                }
            }
        }
        ExpectEq(expected, count, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRoomsExposeDoorsAndReciprocalExits()
{
    mapping opposite = ([
        "north":"south",
        "south":"north",
        "east":"west",
        "west":"east"
    ]);
    string **thresholds = ({
        ({ "/areas/minlach/1x1.c", "east", "/areas/minlach/2x1.c" }),
        ({ "/areas/minlach/0x3.c", "north", "/areas/minlach/0x4.c" }),
        ({ "/areas/minlach/2x2.c", "north", "/areas/minlach/2x3.c" }),
        ({ "/areas/minlach/1x3.c", "east", "/areas/minlach/2x3.c" }),
        ({ "/areas/minlach/2x3.c", "north", "/areas/minlach/2x4.c" }),
        ({ "/areas/minlach/3x3.c", "west", "/areas/minlach/2x3.c" }),
        ({ "/areas/minlach/1x4.c", "east", "/areas/minlach/2x4.c" }),
        ({ "/areas/minlach/3x4.c", "west", "/areas/minlach/2x4.c" }),
        ({ "/areas/minlach/2x2.c", "east", "/areas/minlach/3x2.c" }),
        ({ "/areas/minlach/3x3.c", "south", "/areas/minlach/3x2.c" }),
        ({ "/areas/minlach/3x3.c", "north", "/areas/minlach/3x4.c" }),
        ({ "/areas/minlach/0x4.c", "east", "/areas/minlach/1x4.c" }),
        ({ "/areas/minlach/surrounding/2x1.c", "south",
            "/areas/minlach/surrounding/2x0.c" }),
        ({ "/areas/minlach/surrounding/2x4.c", "north",
            "/areas/minlach/surrounding/2x5.c" }),
        ({ "/areas/minlach/surrounding/1x5.c", "east",
            "/areas/minlach/surrounding/2x5.c" }),
        ({ "/areas/minlach/surrounding/1x6.c", "west",
            "/areas/minlach/surrounding/0x6.c" }),
        ({ "/areas/minlach/surrounding/0x5.c", "north",
            "/areas/minlach/surrounding/0x6.c" })
    });

    foreach (string *threshold in thresholds)
    {
        object exterior = load_object(threshold[0]);
        object interior = load_object(threshold[2]);
        string direction = threshold[1];
        ExpectEq(threshold[2],
            exterior->getExitDirections()["default"][direction],
            threshold[0]);
        ExpectEq(threshold[0],
            interior->getExitDirections()["default"][opposite[direction]],
            threshold[2]);
        ExpectTrue(exterior->isEnvironmentalElement("plank door"),
            threshold[0]);
        ExpectTrue(interior->isEnvironmentalElement("plank door"),
            threshold[2]);
        ExpectEq("door",
            exterior->getEnvironmentalElement("plank door")->Type(),
            threshold[0]);
        ExpectEq("door",
            interior->getEnvironmentalElement("plank door")->Type(),
            threshold[2]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void CaveIconsKeepTheirPassageOpenings()
{
    object region = load_object("/areas/minlach/surrounding/region.c");
    object service = getService("region");
    mapping openings = ([
        "/areas/minlach/surrounding/4x5.c":({ "north", "west" }),
        "/areas/minlach/surrounding/4x6.c":({ "south", "west" }),
        "/areas/minlach/surrounding/3x6.c":({ "south", "east" })
    ]);

    foreach (string path, string *directions in openings)
    {
        object room = load_object(path);
        string **icon = service->getMapIcon(region,
            room->decoratorType(0), "none", "ascii");
        foreach (string direction in ({ "north", "south", "east", "west" }))
        {
            string section = icon[1][0];
            switch (direction)
            {
                case "north": section = icon[0][1]; break;
                case "south": section = icon[2][1]; break;
                case "east": section = icon[1][2]; break;
            }
            ExpectEq(member(directions, direction) >= 0,
                section == " ", path + " " + direction);
            if (member(directions, direction) >= 0)
            {
                ExpectTrue(member(room->getExitDirections()["default"],
                    direction), path);
            }
        }
    }
}
