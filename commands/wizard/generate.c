//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private int Invalid = -2;
private int NotSet = -1;

private object regionDictionary =
    load_object("/lib/dictionaries/regionDictionary.c");

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("generate region [-n(ame|) ##Value##] "
            "[-p(ath|) ##Value##] [-t(ype|) \"##Value##\"] [-x ##Value##] "
            "[-y ##Value##] [-dir(ection|) ##Value##] "
            "[-de(stination|) ##Value##] [-s(ettlement chance|) ##Value##] "
            "[-l(evel|) ##Value##] [-r(ooms|) ##Value##] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getName(string command, object initiator)
{
    string name;

    if (sizeof(regexp(({ command }), "-n(ame)* [0-9A-Za-z_\.\-]+")))
    {
        name = regreplace(command, ".*-n(ame)* ([0-9A-Za-z_\.\-]+).*", "\\2", 1);
    }
    else
    {
        tell_object(initiator, configuration->decorate(
            format("The region name must be specified. The "
                "valid characters are:\nalphanumeric (0-9, A-Z, a-z), '-', "
                "and _.\n", 78), "error message", "wizard commands",
                initiator->colorConfiguration()));
    }
    return name;
}

/////////////////////////////////////////////////////////////////////////////
private string getPath(string command, object initiator)
{
    string path;
    if (sizeof(regexp(({ command }), "-p(ath)* [0-9A-Za-z_\./\-]+")))
    {
        path = regreplace(command, ".*-p(ath)* ([0-9A-Za-z_\./\-]+).*", "\\2", 1);

        if (file_size(path) == -1)
        {
            path = 0;
            tell_object(initiator, configuration->decorate(
                format("The directory specified with the -p(ath) flag does not "
                    "exist. Please create it before continuing.\n", 78), 
                "error message", "wizard commands", initiator->colorConfiguration()));
        }
        else if (!initiator->hasWriteAccess(path))
        {
            path = 0;
            tell_object(initiator, configuration->decorate(
                format("You do not have write access to the specified save "
                    "location.\n", 78), "error message", "wizard commands",
                initiator->colorConfiguration()));
        }
    }
    else
    {
        tell_object(initiator, configuration->decorate(
            format("The save location (path) must be specified. The "
                "valid characters are:\nalphanumeric (0-9, A-Z, a-z), '-', '.', '/'"
                "and _.\n", 78), "error message", "wizard commands",
            initiator->colorConfiguration()));
    }

    if (path && (path[sizeof(path) - 1] != '/'))
    {
        path += "/";
    }

    return path;
}

/////////////////////////////////////////////////////////////////////////////
private string getType(string command, object initiator)
{
    string type = "forest";

    if (sizeof(regexp(({ command }), "-t(ype)* (\"[^\"]+\"|[^ ]+)")))
    {
        type = regreplace(command, ".*-t(ype)* (\"[^\"]+\"|[^ ]+).*", "\\2", 1);
        type -= "\"";

        if (!regionDictionary->isValidRegionType(type))
        {
            type = 0;
            tell_object(initiator, configuration->decorate(
                format("The region type must be a valid region type as defined "
                "in /lib/dictionaries/regions/region-types.h\n", 78), 
                "error message", "wizard commands", initiator->colorConfiguration()));
        }
    }
    return type;
}

/////////////////////////////////////////////////////////////////////////////
private int getDimension(string dimension, string command)
{
    int value = (dimension == "x") ? 25 : 10;

    string flag = sprintf("-%s ", dimension);
    if (sizeof(regexp(({ command }), flag + "[0-9]+")))
    {
        value = 
            to_int(regreplace(command, ".*" + flag + "([0-9]+).*", "\\1", 1));
    }
    return value;
}

/////////////////////////////////////////////////////////////////////////////
private int getSettlementChance(string command, object initiator)
{
    int settlementChance = NotSet;

    if (sizeof(regexp(({ command }), "-s(ettlement chance)* -*[0-9]+")))
    {
        settlementChance = to_int(regreplace(command,
            ".*-s(ettlement chance)* (-*[0-9]+).*", "\\2", 1));

        if ((settlementChance < 0) || settlementChance > 100)
        {
            settlementChance = Invalid;
            tell_object(initiator, configuration->decorate(
                format("The settlement chance must be in the range of 0 to "
                    "100.\n", 78),
                "error message", "wizard commands", initiator->colorConfiguration()));
        }
    }
    return settlementChance;
}

/////////////////////////////////////////////////////////////////////////////
private int getRegionLevel(string command, object initiator)
{
    int level = 0;

    if (sizeof(regexp(({ command }), "-l(evel)* [0-9]+")))
    {
        level = to_int(regreplace(command,
            ".*-l(evel)* ([0-9]+).*", "\\2", 1));

        if ((level < 1) || level > 200)
        {
            level = 0;
            tell_object(initiator, configuration->decorate(
                format("The level must be in the range of 1 to "
                    "200.\n", 78),
                "error message", "wizard commands", initiator->colorConfiguration()));
        }
    }
    return level;
}

/////////////////////////////////////////////////////////////////////////////
private int getRoomsInRegion(string command, object initiator, int x, int y)
{
    int rooms = 0;

    if (sizeof(regexp(({ command }), "-r(ooms)* [0-9]+")))
    {
        rooms = to_int(regreplace(command,
            ".*-r(ooms)* ([0-9]+).*", "\\2", 1));

        int min = (x > y) ? x : y;
        int max = to_int(sqrt(x * y) * 3.0);

        if ((rooms < min) || rooms > max)
        {
            tell_object(initiator, configuration->decorate(
                format(sprintf("The room count (%d) must be in the range of %d to "
                    "%d. This range is calculated based on the values of x "
                    "(%d) and y (%d). Values outside of this range can "
                    "adversely affect the performance of the pathing "
                    "algorithm or lead to poorly-devised regions.\n",
                    rooms, min, max, x, y), 78),
                "error message", "wizard commands", initiator->colorConfiguration()));
            rooms = 0;
        }
    }
    return rooms;
}

/////////////////////////////////////////////////////////////////////////////
private string getDirection(string command)
{
    string direction;

    if (sizeof(regexp(({ command }), "-dir(ection)* (north|south|east|west)")))
    {
        direction = regreplace(command,
            ".*-dir(ection)* (north|south|east|west).*", "\\2", 1);
    }
    return direction;
}

/////////////////////////////////////////////////////////////////////////////
private string getDestination(string command)
{
    string destination;

    if (sizeof(regexp(({ command }), "-de(stination)* [0-9A-Za-z_\./\-]+")))
    {
        destination = regreplace(command,
            ".*-de(stination)* ([0-9A-Za-z_\./\-]+).*", "\\2", 1);
    }
    return destination;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateRegion(object initiator, string name, string type,
    int x, int y, int settlementChance, string direction, string destination,
    string path, int level, int rooms)
{
    object region = clone_object("/lib/environment/region.c");
    region->setRegionName(name);
    region->setRegionType(type);
    region->setDimensions(x, y);

    if (settlementChance != NotSet)
    {
        region->setSettlementChance(settlementChance);
    }

    if (level)
    {
        region->setRegionLevel(level);
    }

    if (rooms)
    {
        region->setRoomCount(rooms);
    }

    region->createRegion(direction, destination);
    tell_object(initiator, region->displayMap(initiator));
    tell_object(initiator, configuration->decorate(format("\nType 'C' to create, "
        "'R' to generate a different region, or anything else to abort.\n", 78),
        "directory", "wizard commands", initiator->colorConfiguration()));

    input_to("responseToGenerate", 1 | 2, region, initiator, name, type,
        x, y, settlementChance, direction, destination, path, level, rooms);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void responseToGenerate(string response, object region,
    object initiator, string name, string type, int x, int y, 
    int settlementChance, string direction, string destination, string path,
    int level, int rooms)
{
    response = lower_case(response);
    if (response == "c")
    {
        tell_object(initiator, configuration->decorate("You have "
            "generated this region.\n",
            "normal", "wizard commands", initiator->colorConfiguration()));
        region->generateStaticFiles(path, 1);
        destruct(region);
    }
    else if (response == "r")
    {
        destruct(region);
        tell_object(initiator, configuration->decorate("Regenerating "
            "region...\n",
            "normal", "wizard commands", initiator->colorConfiguration()));
        generateRegion(initiator, name, type, x, y, settlementChance,
            direction, destination, path, level, rooms);
    }
    else
    {
        destruct(region);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("generate"))
    {
        ret = 1;
        string name = getName(command, initiator);
        string path = getPath(command, initiator);

        if (name && path)
        {

            string type = getType(command, initiator);

            int x = getDimension("x", command);
            int y = getDimension("y", command);

            if (!regionDictionary->validDimensions(x, y))
            {
                x = 0;
                y = 0;
                tell_object(initiator, configuration->decorate(
                    format("The x and y dimensions must be between 5-25. "
                        "The best visualization occurs when the dimensions "
                        "are 25x10.\n", 78),
                    "error message", "wizard commands", initiator->colorConfiguration()));
            }

            int settlementChance = getSettlementChance(command, initiator);
            string direction = getDirection(command);
            string destination = getDestination(command);
            int level = getRegionLevel(command, initiator);
            int rooms = getRoomsInRegion(command, initiator, x, y);

            if (x && y && type && (settlementChance != Invalid))
            {
                generateRegion(initiator, name, type, x, y, settlementChance,
                    direction, destination, path, level, rooms);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Create a randomly-generated region.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The generate region command will create a randomly-generated "
        "region and place the source files in the supplied path provided the "
        "user has write access.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-n":
        {
            ret = "This option will set the name of the region. This is a "
                "required parameter.";
            break;
        }
        case "-dir":
        {
            ret = "This option sets the exit direction for the region - in "
                "other words, the direction of the exit to the location "
                "specified by the -de(stination) flag. This parameter, while "
                "optional, must be paired with the -de flag.";
            break;
        }
        case "-de":
        {
            ret = "This option sets the destination of the exit for the region. "
                "This parameter, while optional, must be paired with the -dir "
                "flag.";
            break;
        }
        case "-p":
        {
            ret = "This option will set the path to which the generated region "
                "will be written. You must have write access to this path. "
                "This is a required parameter.";
            break;
        }
        case "-s":
        {
            ret = "For those region types that can generate settlements, this "
                "parameter will override the default chance that a settlement "
                "will be generated.";
            break;
        }
        case "-t":
        {
            ret = "This option will set the type of the region. Valid values are "
                "specified in /lib/dictionaries/regions/region-types.h. If "
                "no value is set, this will default to 'forest'.";
            break;
        }
        case "-x":
        {
            ret = "This option will set the x dimension for the region. This value "
                "must range from 5 to 25. The default value is 25.";
            break;
        }
        case "-y":
        {
            ret = "This option will set the y dimension for the region. This value "
                "must range from 5 to 25. The default value is 10.";
            break;
        }
        case "-l":
        {
            ret = "This option will set the level of the NPCs generated for this "
                "region. There will be some variance in levels due to the "
                "external constraints of potential encounters.";
            break;
        }
        case "-r":
        {
            ret = "This option will set the number of rooms with encounters that are "
                "generated for the region. This value must range between the larger "
                "of the X or Y dimension as a minimum to three times the square root "
                "of the area of the region as a maximum. The reason for this is because "
                "the pathing algorithm can become unperformant in scenarios outside of "
                "those bounds.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: /lib/dictionaries/regions/region-types.h";
}
