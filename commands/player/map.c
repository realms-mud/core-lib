//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("map");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        object environment = environment(initiator);
        if (environment)
        {
            string map = environment->getRegion() ?
                environment->getRegion()->displayMap(initiator,
                    environment->currentState()) : 0;

            if (stringp(map))
            {
                tell_object(initiator, map);
            }
            else
            {
                tell_object(initiator,
                    configuration->decorate(
                        "There is no map available for this area.\n",
                        "message", "soul", initiator->colorConfiguration()));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "View a map of the area you are in";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The map command will display a map of the area that "
        "you are currently in.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "The mapping functionality is not available "
        "in all areas - specifically the mud's legacy sections.";
}
