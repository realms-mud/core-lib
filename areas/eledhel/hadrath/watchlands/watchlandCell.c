//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

protected void setWatchlandCell(int x, int y)
{
    string *landmarks = ({
        "the Rilwen barley plots", "the old boundary oak",
        "the King's Road turning", "the Stag's Well",
        "the reeve's gate", "the west watchtower",
        "the sheep-fold run", "the stone ditch",
        "the low ridge", "the ash grove", "the red ford track",
        "the patrol's cookfire", "the millward field",
        "the shepherd's cut", "the briar lane",
        "the garrison orchard", "the east pasture",
        "the war-camp track", "the wellhouse field",
        "the southern boundary"
    });
    string *belts = ({
        "north slope", "north fields", "hedgerow fringe",
        "upper pasture", "watch road", "keep approach",
        "lower pasture", "mill brook", "south meadow",
        "wood edge"
    });
    string base = "/areas/eledhel/hadrath/watchlands/";
    int northExit = y > 0;
    int southExit = y < 9;
    int westExit = x > 0;
    int eastExit = x < 19;
    string decorator = "village square";

    if (y < 2 || (y >= 6 && y < 8))
    {
        setTerrain("/lib/environment/terrain/farmland.c");
    }
    else if (y < 4)
    {
        setTerrain("/lib/environment/terrain/forest-clearing.c");
    }
    else if (y < 6)
    {
        setTerrain("/lib/environment/terrain/plains.c");
    }
    else
    {
        setTerrain("/lib/environment/terrain/forest.c");
    }

    setShortDescription("Hadrath's " + landmarks[x] + " along the " +
        belts[y] + ".");

    if (x > 0)
    {
        addExit("west", base + to_string(x - 1) + "x" +
            to_string(y) + ".c");
        addFeature("/lib/environment/features/paths/path.c", "west");
    }
    if (x < 19)
    {
        addExit("east", base + to_string(x + 1) + "x" +
            to_string(y) + ".c");
        addFeature("/lib/environment/features/paths/path.c", "east");
    }
    if (y > 0)
    {
        addExit("north", base + to_string(x) + "x" +
            to_string(y - 1) + ".c");
        addFeature("/lib/environment/features/paths/path.c", "north");
    }
    if (y < 9)
    {
        addExit("south", base + to_string(x) + "x" +
            to_string(y + 1) + ".c");
        addFeature("/lib/environment/features/paths/path.c", "south");
    }
    if (x == 0 && y == 0)
    {
        addExit("north", "/areas/eledhel/south-rural-route-08/18x2.c");
        northExit = 1;
    }
    if (x == 19 && y == 5)
    {
        addExit("east", "/areas/eledhel/hadrath/grounds/0x2.c");
        addFeature("/lib/environment/features/paths/path.c", "east");
        eastExit = 1;
    }

    if (northExit && southExit && eastExit && westExit)
    {
        decorator = "village road intersection";
    }
    else if (northExit && eastExit && westExit && !southExit)
    {
        decorator = "village road T-north";
    }
    else if (southExit && eastExit && westExit && !northExit)
    {
        decorator = "village road T-south";
    }
    else if (northExit && southExit && eastExit && !westExit)
    {
        decorator = "village road T-east";
    }
    else if (northExit && southExit && westExit && !eastExit)
    {
        decorator = "village road T-west";
    }
    else if (northExit && southExit)
    {
        decorator = "village north-south road";
    }
    else if (eastExit && westExit)
    {
        decorator = "village east-west road";
    }
    else if (northExit && eastExit)
    {
        decorator = "village road corner NE";
    }
    else if (northExit && westExit)
    {
        decorator = "village road corner NW";
    }
    else if (southExit && eastExit)
    {
        decorator = "village road corner SE";
    }
    else if (southExit && westExit)
    {
        decorator = "village road corner SW";
    }
    addDecorator(decorator);

    if ((x + y) % 6 == 0)
    {
        setEncounterLevel(3 + (x % 2));
        if (y < 4)
        {
            addRandomCreature(({ "groundhog", "white-tail deer",
                "red fox" }));
        }
        else if (y < 7)
        {
            addRandomCreature(({ "red fox", "boar", "outlaw" }));
        }
        else
        {
            addRandomCreature(({ "ruffian", "outlaw", "gray wolf" }));
        }
    }
    if (x >= 15 && y >= 7 && (x + y) % 3 == 0 &&
        (x + y) % 6 != 0)
    {
        setEncounterLevel(4);
        addRandomCreature(({ "outlaw", "ruffian", "boar" }));
    }
    if (x == 6 && y == 1)
    {
        addObject("/areas/eledhel/hadrath/characters/maereth.c");
    }
    if (x == 16 && y == 8)
    {
        addObject("/areas/eledhel/hadrath/characters/daerwen.c");
    }
}
