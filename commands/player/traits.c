//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
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
