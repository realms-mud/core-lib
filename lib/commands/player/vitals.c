//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Player Information";
    addCommandTemplate("vitals");

    Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;

        tell_object(initiator, initiator->vitals());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display a character's vitals";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The vitals command displays information about your current hit "
        "points, spell points, and stamina points levels.\n\nFor example:\n> "
        "vitals", 78) + 
        configuration->decorate("Hit Points: ",
            "content", "score", colorConfiguration) +
        configuration->decorate("==",
            "bar", "score", colorConfiguration) +
        configuration->decorate("........",
            "empty bar", "score", colorConfiguration) +
        configuration->decorate("   Spell Points: ",
            "content", "score", colorConfiguration) +
        configuration->decorate("========",
            "bar", "score", colorConfiguration) +
        configuration->decorate("..",
            "empty bar", "score", colorConfiguration) +
        configuration->decorate("       Stamina: ",
            "content", "score", colorConfiguration) +
        configuration->decorate("========== ", 
            "bar", "score", colorConfiguration) +
        configuration->decorate("                30 / 121                    "
            "122 / 152                 96 / 96  ", 
            "information", "score", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: score";
}
