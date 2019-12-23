//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Player Information";
        addCommandTemplate("traits [-b(ackground|)] [-d(etails|)] [-ed(ucational|)] "
            "[-ef(fect|)] [-ge(netic|)] [-g(uild|)] [-h(ealth|)] [-pe(rsonality|)] "
            "[-pr(ofessional|)] [-ra(cial|)] [-ro(le|)] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeListTraits(string command, object initiator)
{
    string *types = ({});
    if (sizeof(regexp(({ command }), "-b(ackground)*( |$)")))
    {
        types += ({ "background" });
    }
    if (sizeof(regexp(({ command }), "-ed(ucational)*( |$)")))
    {
        types += ({ "educational" });
    }
    if (sizeof(regexp(({ command }), "-ef(fect)*( |$)")))
    {
        types += ({ "effect" });
    }
    if (sizeof(regexp(({ command }), "-ge(netic)*( |$)")))
    {
        types += ({ "genetic" });
    }
    if (sizeof(regexp(({ command }), "-g(uild)*( |$)")))
    {
        types += ({ "guild" });
    }
    if (sizeof(regexp(({ command }), "-h(ealth)*( |$)")))
    {
        types += ({ "health" });
    }
    if (sizeof(regexp(({ command }), "-pe(rsonality)*( |$)")))
    {
        types += ({ "personality" });
    }
    if (sizeof(regexp(({ command }), "-pr(ofessional)*( |$)")))
    {
        types += ({ "professional" });
    }
    if (sizeof(regexp(({ command }), "-ra(cial)*( |$)")))
    {
        types += ({ "racial" });
    }
    if (sizeof(regexp(({ command }), "-ro(le)*( |$)")))
    {
        types += ({ "role" });
    }
    if (sizeof(regexp(({ command }), "-a(ll)*( |$)")) ||
        (command == "traits"))
    {
        types += ({ "health", "educational", "personality", "genetic",
            "professional", "guild", "role", "effect", "background", "racial" });
    }

    if (sizeof(types))
    {
        tell_object(initiator, initiator->traitsList(types));
    }

    return sizeof(types) > 0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int executeTraitDetails(string command, object initiator)
{
    int ret = 0;

    if (sizeof(regexp(({ command }), "-d(etails)* [A-Za-z ]+")))
    {
        string trait = regreplace(command, "traits -d(etails)* ([A-Za-z ]+)",
            "\\2");

        object dictionary = 
            load_object("/lib/dictionaries/traitsDictionary.c");

        if (dictionary)
        {
            string message = dictionary->traitDetails(trait);

            if (message)
            {
                ret = 1;
                tell_object(initiator, message);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        notify_fail("traits: invalid subcommand.\n");

        ret = executeTraitDetails(command, initiator) ||
            executeListTraits(command, initiator);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display trait information.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-*[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-b":
        {
            ret = "This option will filter the list of traits to display "
                "background traits.";
            break;
        }
        case "-d":
        {
            ret = "This option will display details about the specified "
                "trait.";
            break;
        }
        case "-ed":
        {
            ret = "This option will filter the list of traits to display "
                "educational traits.";
            break;
        }
        case "-ef":
        {
            ret = "This option will filter the list of traits to display "
                "traits that the character has due to an active magical "
                "or biological trait.";
            break;
        }
        case "-ge":
        {
            ret = "This option will filter the list of traits to display "
                "genetic traits.";
            break;
        }
        case "-g":
        {
            ret = "This option will filter the list of traits to display "
                "guild traits.";
            break;
        }
        case "-h":
        {
            ret = "This option will filter the list of traits to display "
                "health traits.";
            break;
        }
        case "-pe":
        {
            ret = "This option will filter the list of traits to display "
                "personality traits.";
            break;
        }
        case "-pr":
        {
            ret = "This option will filter the list of traits to display "
                "professional traits.";
            break;
        }
        case "-ra":
        {
            ret = "This option will filter the list of traits to display "
                "racial traits.";
            break;
        }
        case "-ro":
        {
            ret = "This option will filter the list of traits to display "
                "traits gained through one of the player's roles.";
            break;
        }
    }

    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The traits command is used to display a player's traits "
        "or details about the specified trait.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: score";
}
