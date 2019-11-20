//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";

private mapping mapIcons = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int isDomainRegion()
{
    return sizeof(mapIcons) > 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getLayoutRow(string row)
{
    string colorString = 0;

    string *ret = regexplode(row, "(\x1b[^m]+m)*(\xe2..|.)(\x1b.0m|)") - 
        ({ "" });

    for (int i = 0; i < sizeof(ret); i++)
    {
        if (sizeof(regexp(({ ret[i] }), "\x1b[^m]+m")) &&
            !sizeof(regexp(({ ret[i] }), "\x1b.0m")))
        {
            colorString = regreplace(ret[i], "(\x1b[^m]+m).*$", "\\1", 1);
        }
        else if (colorString)
        {
            ret[i] = colorString + ret[i];
        }

        if (sizeof(regexp(({ ret[i] }), "\x1b.0m")))
        {
            colorString = 0;
        }
    }
    return ret + ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateIconsForDomain(mapping domainInfo)
{
    if (member(domainInfo, "layout") && sizeof(domainInfo["layout"]))
    {
        int yDimension = sizeof(domainInfo["layout"]);
        int xDimension;

        string emptyRow = sprintf("%51s", "");

        for (int y = 0; y < yDimension; y += 3)
        {
            string *row0 = getLayoutRow(domainInfo["layout"][y]);
            xDimension = sizeof(row0);

            string *row1 = getLayoutRow(((y + 1) < yDimension) ? 
                    domainInfo["layout"][y + 1] : emptyRow);

            string *row2 = getLayoutRow(((y + 2) < yDimension) ?
                domainInfo["layout"][y + 2] : emptyRow);

            for (int x = 0; x < xDimension; x += 3)
            {
                mapIcons[sprintf("%dx%d", (x / 3) + domainInfo["x-offset"], 
                    ((yDimension - y) / 3) + domainInfo["y-offset"])] = ({
                    ({ row0[x], row0[x + 1], row0[x + 2] }),
                    ({ row1[x], row1[x + 1], row1[x + 2] }),
                    ({ row2[x], row2[x + 1], row2[x + 2] }),
                });
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void loadDomain(object user, string domainName)
{
    MaxX = 25;
    MaxY = 10;

    object domainDictionary =
        load_object("/lib/dictionaries/domainDictionary.c");

    mapping domainInfo = domainDictionary->getPlayerDomain(
        user, domainName, user->getDomainType(domainName));

    generateIconsForDomain(domainInfo);

    for (int i = 0; i < MaxX; i++)
    {
        grid[i] = ([]);
        for (int j = 0; j < MaxY; j++)
        {
            string location = sprintf("%dx%d", i, j);
            grid[i][j] = ([
                "x": i,
                "y": j,
                "room type": "none",
                "is placed": 0,
                "exits": ([]),
                "environment": 0
            ]);

            if (member(mapIcons, location))
            {
                grid[i][j]["room type"] = location;
                grid[i][j]["is placed"] = 1;
                grid[i][j]["environment"] =
                    clone_object("/lib/environment/generatedEnvironment");
                grid[i][j]["environment"]->addDecorator(location);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string **getDomainMapIcon(string location)
{
    return (member(mapIcons, location)) ? mapIcons[location] : 
        ({ ({ " ", " ", " " }),
           ({ " ", " ", " " }),
           ({ " ", " ", " " }) });
}
