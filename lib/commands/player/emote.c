//******************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Emote / Soul";
    addCommandTemplate("emote [.*]");
    addCommandTemplate(": [.*]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) || (command[0] == ':'))
    {
        // This is stripping out escape characters and the command.
        string message = initiator->Name() + " " + 
            regreplace(command, "^(emote|:) ", "", 1);
        message -= "\x1b";

        if (environment(initiator))
        {
            object configuration = getService("configuration");

            object *characters = filter(all_inventory(environment(initiator)),
                (: $1->isRealizationOfLiving() :));

            foreach(object person in characters)
            {
                if (person && objectp(person))
                {
                    if (!person->blocked(initiator))
                    {
                        tell_object(person, configuration->decorate(
                            format(message, 78), "message", "soul",
                            person->colorConfiguration()));
                    }
                }
            }
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display a custom action/emote by the player";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("This command allows the user to display a custom "
        "message to those in their environment. As with other forms of "
        "communication, be mindful of those you interact with and adhere "
        "to the 'don't be a jerk' policy.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: The various soul commands";
}
