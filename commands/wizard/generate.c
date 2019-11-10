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
            "[-de(stination|) ##Value##] [-s(ettlement chance|) ##Value##][.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getName(string command, object initiator)
{
    string name;

    if (sizeof(regexp(({ command }), "-n(ame)* [0-9A-Za-z_.\-]+")))
    {
        name = regreplace(command, ".*-n(ame)* ([0-9A-Za-z_.\-]+).*", "\\2", 1);
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
    if (sizeof(regexp(({ command }), "-p(ath)* [0-9A-Za-z_./\-]+")))
    {
        path = regreplace(command, ".*-p(ath)* ([0-9A-Za-z_./\-]+).*", "\\2", 1);

        if (!initiator->hasWriteAccess(path))
        {
            path = 0;
            tell_object(initiator, configuration->decorate(
                format("You do not have write access to the specified save "
                    "location.\n", 78), "error message", "wizard commands",
                initiator->colorConfiguration()));
        }
        else if (file_size(path) == -1)
        {
            path = 0;
            tell_object(initiator, configuration->decorate(
                format("The directory specified with the -p(ath) flag does not "
                    "exist. Please create it before continuing.\n", 78), 
                "error message", "wizard commands", initiator->colorConfiguration()));
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

    if (sizeof(regexp(({ command }), "-t(ype)* \"[^\"]+\"")))
    {
        type = regreplace(command, ".*-t(ype)* \"([^\"]+)\".*", "\\2", 1);

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

    if (sizeof(regexp(({ command }), "-s(ettlement chance)* [0-9]+")))
    {
        settlementChance = to_int(regreplace(command,
            ".*-s(ettlement chance)* [0-9]+.*", "\\2", 1));

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

    if (sizeof(regexp(({ command }), "-de(stination)* [0-9A-Za-z_./\-]+")))
    {
        destination = regreplace(command,
            ".*-de(stination)* ([0-9A-Za-z_./\-]+) .*", "\\2", 1);
    }
    return destination;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void generateRegion(object region, object initiator,
    string direction, string destination)
{
    region->createRegion(direction, destination);
    tell_object(initiator, region->displayMap(initiator));
    tell_object(initiator, configuration->decorate(format("\nType 'C' to create, "
        "'R' to generate a different region, or anything else to abort.\n", 78),
        "directory", "wizard commands", initiator->colorConfiguration()));

    input_to("responseToGenerate", 1 | 2, region, initiator, direction, destination);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void responseToGenerate(string response, object region,
    object initiator, string direction, string destination)
{
    response = lower_case(response);
    if (response == "c")
    {
        tell_object(initiator, configuration->decorate("You have "
            "generated this region.\n",
            "normal", "wizard commands", initiator->colorConfiguration()));
    }
    else if (response == "r")
    {
        tell_object(initiator, configuration->decorate("Regenerating "
            "region...\n",
            "normal", "wizard commands", initiator->colorConfiguration()));
        generateRegion(region, initiator, direction, destination);
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

            if (x && y && type && (settlementChance != Invalid))
            {
                object region = clone_object("/lib/environment/region.c");
                region->setRegionName(name);
                region->setRegionType(type);
                region->setDimensions(x, y);
                
                if (settlementChance != NotSet)
                {
                    region->setSettlementChange(settlementChance);
                }

                generateRegion(region, initiator, direction, destination);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Create a directory.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The mkdir command will create the specified directory "
        "provided the user has write access.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: rm, cp, and mv";
}
