//******************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Emote / Soul";
        addCommandTemplate("emote [.*]");
        addCommandTemplate(": [.*]");
    }
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
            object configuration = load_object("/lib/dictionaries/configurationDictionary.c");
            foreach(object person in all_inventory(environment(initiator)))
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
