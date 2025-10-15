//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/regions/core.c";
#include "/lib/environment/modules/regions/display-characters.h"

private object configuration = getService("configuration");

/////////////////////////////////////////////////////////////////////////////
private nomask int hasExit(mapping location, string direction)
{
    return member(location["exits"], direction) ||
        ((member(({ "entry", "exit" }), location["room type"]) > -1) &&
        (location["exit to"] == direction));
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string displayCell(mapping location, 
    string defaultCell, string colorConfiguration, string charset, 
    int userHere, string direction)
{
    if (!direction)
    {
        direction = "none";
    }

    if ((location["room type"] == "none") && userHere)
    {
        string backgroundColor = "";
        switch (colorConfiguration)
        {
            case "3-bit":
            {
                backgroundColor = "41;";
                break;
            }
            case "8-bit":
            {
                backgroundColor = "48;5;52;";
                break;
            }
            case "24-bit":
            {
                backgroundColor = "48;2;90;0;0;";
                break;
            }
        }

        defaultCell =
            !sizeof(regexp(({ defaultCell }), "[[]0;(41;|48;5|48;2)")) ?
                regreplace(defaultCell, "(\x1b[[]0;)([^m]+)",
                    "\\1" + backgroundColor + "\\2", 1) :
                regreplace(defaultCell, "(\x1b[[]0;)(4[0-9];(5;[0-9]+;|2;[0-9]+;[0-9]+;[0-9]+;|))([^m]+)",
                    "\\1" + backgroundColor + "\\4", 1);
    }

    return (hasExit(location, direction) && (member(({ "room", "path", "entry", 
        "exit", "training ground" }), location["room type"]) > -1)) ?
        configuration->decorate(displayCharacter[direction][charset],
            (userHere ? "user location" : "exit"), "map", colorConfiguration) :
        configuration->decorate(defaultCell, (userHere ? "reverse" : "none"),
            "map", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateCustomIcon(string **icon)
{
    return pointerp(icon) && (sizeof(icon) == 3) &&
        (sizeof(icon[0]) == 3) &&
        (sizeof(icon[1]) == 3) &&
        (sizeof(icon[2]) == 3);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int userInLocation(object user, object location)
{
    object playerEnvironment = objectp(user) ? environment(user) : 0;

    return objectp(playerEnvironment) && objectp(location) && 
        objectp(playerEnvironment->getRegion()) && 
        objectp(location->getRegion()) &&
        (playerEnvironment->getRegion()->regionName() == 
            location->getRegion()->regionName()) &&
        (playerEnvironment->getCoordinates() == location->getCoordinates());
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string displayMapSection(object user, int startX, 
    int startY, int endX, int endY, string state, int addDivider)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();

    string map = "";

    if (user)
    {
        for (int y = startY; y >= endY; y--)
        {
            string *row = ({ "", "", "", "" });

            for (int x = startX; x <= endX; x++)
            {
                mapping location = grid[x][y];

                if(member(location, "state exits") && objectp(location["environment"]))
                {
                    string *exits = member(location["state exits"], state) ?
                        m_indices(location["state exits"][state]) : ({});

                    location["exits"] = ([]);
                    if(sizeof(exits))
                    {
                        foreach(string direction in exits)
                        {
                            location["exits"][direction] = ([
                                "region":this_object(),
                                "destination" : "manual"
                            ]);
                        }
                    }
                }

                if (location["room type"] == "building")
                {
                    row[0] += configuration->decorate(location["icon"][charset][0],
                        location["icon"]["color"], "map", colorConfiguration);
                    row[1] += configuration->decorate(location["icon"][charset][1],
                        location["icon"]["color"], "map", colorConfiguration);
                    row[2] += configuration->decorate(location["icon"][charset][2],
                        location["icon"]["color"], "map", colorConfiguration);
                }
                else
                {
                    int userHere = objectp(present(user, location["environment"])) ||
                        userInLocation(user, location["environment"]);

                    string decoratorType = objectp(location["environment"]) ?
                        location["environment"]->decoratorType(state) : 
                        (member(location, "decorator type") ? location["decorator type"] : location["room type"]);

                    string **icon = RegionService->getMapIcon(this_object(),
                        decoratorType, colorConfiguration, charset);
                    if (objectp(location["environment"]))
                    {
                        string **customIcon = 
                            location["environment"]->customIcon(icon, 
                                colorConfiguration, charset);

                        if (validateCustomIcon(customIcon))
                        {
                            icon = customIcon;
                        }
                        else
                        {
                            raise_error(sprintf("Map.c: Custom icon returned by %O "
                                "was not valid.\n", location["environment"]));
                        }
                    }

                    row[0] += sprintf("%s%s%s", 
                        displayCell(location, icon[0][0], colorConfiguration, 
                            charset, userHere, "northwest"),
                        displayCell(location, icon[0][1], colorConfiguration,
                            charset, userHere, "north"),
                        displayCell(location, icon[0][2], colorConfiguration,
                            charset, userHere, "northeast"));

                    string roomType = location["room type"];
                    int useRoom = member(displayCharacter, roomType) &&
                        (icon[1][1] == " ");

                    row[1] += sprintf("%s%s%s",
                        displayCell(location, icon[1][0], colorConfiguration,
                            charset, userHere, "west"),
                        configuration->decorate(
                        (userHere ? displayCharacter["player"][charset] :
                            (useRoom ? 
                                displayCharacter[roomType][charset] : 
                                sprintf("%s%s%s",
                                    RegionService->iconColor(decoratorType, colorConfiguration),
                                    icon[1][1],
                                    (colorConfiguration != "none") ? "\x1b[0m" : ""))),
                            (userHere ? "user location" : roomType),
                            "map", colorConfiguration),
                        displayCell(location, icon[1][2], colorConfiguration,
                            charset, userHere, "east"));

                    row[2] += sprintf("%s%s%s",
                        displayCell(location, icon[2][0], colorConfiguration,
                            charset, userHere, "southwest"),
                        displayCell(location, icon[2][1], colorConfiguration,
                            charset, userHere, "south"),
                        displayCell(location, icon[2][2], colorConfiguration,
                            charset, userHere, "southeast"));
                }
            }

            string divider = !addDivider ? "" :
                configuration->decorate(displayCharacter["divider"][charset],
                    "divider", "map", colorConfiguration);

            map += sprintf("%s%s\n%s%s\n%s%s\n", row[0], divider, row[1], 
                divider, row[2], divider);
        }
    }
    return map;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getMiniMap(object environment, object user, 
    string state)
{
    string map = 0;

    if (!state)
    {
        state = "default";
    }

    if (environment)
    {
        string coordinates = environment->getCoordinates();
        if (coordinates)
        {
            int xCoordinate = to_int(regreplace(coordinates, "([0-9]+)x.*", "\\1", 1));
            int endX = (xCoordinate == (MaxX - 1)) ? (MaxX - 1) : xCoordinate +
                ((xCoordinate == 0) ? 2 : 1);
            int startX = xCoordinate ? xCoordinate - ((endX == (MaxX - 1)) ? 2 : 1) : 0;

            int yCoordinate = to_int(regreplace(coordinates, ".*x([0-9]+)", "\\1", 1));
            int startY = (yCoordinate == (MaxY - 1)) ? (MaxY - 1) : yCoordinate +
                ((yCoordinate == 0) ? 2 : 1);
            int endY = yCoordinate ? yCoordinate - ((yCoordinate == (MaxY - 1)) ? 2 : 1) : 0;

            map = displayMapSection(user, startX, startY, endX, endY, state, 1);
        }
    }
    return map ? explode(map, "\n") : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string displayMap(object user, string state)
{
    if (!state)
    {
        state = "default";
    }
    return "\n" + displayMapSection(user, 0, MaxY - 1, MaxX - 1, 0, state);
}
