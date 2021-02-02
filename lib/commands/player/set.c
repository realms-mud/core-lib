//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

private mapping parametersToFunction = ([
    "message in": ([
        "method": "MessageIn",
        "description": "The message displayed when entering an environment",
        "wizard only": 1
    ]),
    "msgin": ([
        "method": "MessageIn",
        "description": "The message displayed when entering an environment",
        "wizard only": 1
    ]),
    "message out": ([
        "method": "MessageOut",
        "description": "The message displayed when leaving an environment",
        "wizard only": 1
    ]),
    "msgout": ([
        "method": "MessageOut",
        "description": "The message displayed when leaving an environment",
        "wizard only": 1
    ]),
    "magical message in": ([
        "method": "MagicalMessageIn",
        "description": "The message displayed when entering an environment "
            "without a direct movement action",
        "wizard only": 1
    ]),
    "mmsgin": ([
        "method": "MagicalMessageIn",
        "description": "The message displayed when entering an environment "
            "without a direct movement action",
        "wizard only": 1
    ]),
    "magical message out": ([
        "method": "MagicalMessageOut",
        "description": "The message displayed when leaving an environment "
            "without a direct movement action",
        "wizard only": 1
    ]),
    "mmsgout": ([
        "method": "MagicalMessageOut",
        "description": "The message displayed when leaving an environment "
            "without a direct movement action",
        "wizard only": 1
    ]),
    "message home": ([
        "method": "MessageHome",
        "description": "The message displayed when executing the 'home' command",
        "wizard only": 1
    ]),
    "home message": ([
        "method": "MessageHome",
        "description": "The message displayed when executing the 'home' command",
        "wizard only": 1
    ]),
    "message clone": ([
        "method": "MessageClone",
        "description": "The message displayed when cloning an object",
        "wizard only": 1
    ]),
    "clone message": ([
        "method": "MessageClone",
        "description": "The message displayed when cloning an object",
        "wizard only": 1
    ]),
    "home location": ([
        "method": "HomeLocation",
        "description": "Sets the location the user goes to when using the 'home' command",
        "wizard only": 1
    ]),
    "starting location": ([
        "method": "StartLocation",
        "description": "Sets the location the user goes to upon login",
        "wizard only": 1
    ]),
    "title": ([
        "method": "Title",
        "description": "Sets the user's title",
        "wizard only": 1
    ]),
    "pretitle": ([
        "method": "Pretitle",
        "description": "Sets the user's pretitle",
        "wizard only": 1
    ]),
    "short": ([
        "method": "short",
        "description": "Sets the user's short description",
        "wizard only": 1
    ]),
    "short description": ([
        "method": "short",
        "description": "Sets the user's short description",
        "wizard only": 1
    ]),
    "description": ([
        "method": "description",
        "description": "Sets the user's detailed character description",
        "wizard only": 0
    ]),
    "long description": ([
        "method": "description",
        "description": "Sets the user's detailed character description",
        "wizard only": 0
    ]),
     "primary guild": ([
        "method": "primaryGuildSetting",
        "description": "Sets the primary / shown guild for a player in lists and "
            "other commands that identify the player with 'what they do'",
        "suppress message" : 1,
        "wizard only": 0
    ]),
    "page size": ([
        "method": "pageSize",
        "description": "Sets the number of lines the pager will display at a time",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "color": ([
        "method": "colorConfiguration",
        "description": "Sets the user's color configuration. This can be:\n"
            "none - Use this option for no color support\n"
            "grayscale - Use this option for grayscale\n        (26 shades) support\n"
            "3-bit - Use this option for basic 3-bit\n        (8 color) support\n"
            "8-bit - Use this option for 8-bit (256\n        color) support\n"
            "24-bit - Use this option for true color\n        (16,777,216 color) support\n"
            "\nBe sure that your terminal / mud client supports the selected "
            "color option to ensure proper display.\n",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "charset": ([
        "method": "charsetConfiguration",
        "description": "Sets the user's character set configuration. This can be:\n"
            "ascii - Use this option for standard ASCII\n"
            "unicode - Use this option for unicode\n"
            "\nBe sure that your terminal / mud client supports the selected "
            "character set option to ensure proper display.\n",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "combat verbosity": ([
        "method": "combatVerbosity",
        "description": "Sets the level of detail displayed during combat. This can be:\n"
            "normal - All attacks are displayed, whether\n"
            "         they are hits or misses\n"
            "only hits - Only successful attacks are\n"
            "            displayed\n"
            "digest - A summary message is shown every\n"
            "         few rounds or if damage greater\n"
            "         than 25% of your total is taken\n"
            "show vitals - Combatant vitals are displayed\n"
            "              with all attacks\n"
            "periodic vitals - Vitals are displayed with\n"
            "                  the digest view\n",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "busy": ([
        "method": "setBusy",
        "description": "Sets the user's 'busy' flag. When this is set, you will not "
            "receive directed messages (tells) from other players.\n"
            "Possible values are: on, off",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "earmuffs": ([
        "method": "setEarmuffs",
        "description": "Sets the user's earmuffs. When this is set, you will not "
            "receive shouts or poses from other players.\n"
            "Possible values are: on, off",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "block player": ([
        "method": "block",
        "description": "This parameter will allow you to block all communication from "
            "the specified user. They will not be able to 'tell' to you nor will they "
            "be able to execute a soul command on you. You will not see their say, "
            "emote, undirected soul commands, shouts, poses, or channel (guild, race, "
            "etc) messages either. You will, however, see when they arrive, leave, and "
            "all combat messages.",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "unblock player": ([
        "method": "unblock",
        "description": "This parameter will allow you to unblock a previously-blocked "
            "player.",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "silence": ([
        "method": "silence",
        "description": "This parameter will allow you 'turn off' the specified channel. "
            "For example, if your fighter guild is too chatty for your tastes\n"
            "\t\tset -p silence -v fighter\n"
            "and you won't hear from them until you unsilence. You cannot silence the 'system' "
            "channel.",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "unsilence": ([
        "method": "unsilence",
        "description": "This parameter will allow you unsilence a previously-silenced "
            "channel",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "pvp": ([
        "method": "configurePVPSetting",
        "description": "This parameter will allow you to attack and be attacked by "
            "other players. Once this flag is set, it cannot be unset!",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "unsafe faction interactions": ([
        "method": "toggleUnsafeFactionInteractions",
        "description": "This parameter will allow you to attack characters that "
            "belong to factions you are either a member of or friendly towards. "
            "Be warned - killing members of these factions will have negative "
            "effects!",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "display map": ([
        "method": "setMiniMap",
        "description": "Toggles whether or not the user will see the mini map when "
            "it's available.\n"
            "Possible values are: on, off",
        "suppress message": 1,
        "wizard only": 0
    ]),
    "display comparison": ([
        "method": "setLevelComparison",
        "description": "Toggles whether or not the user will see a level comparison "
            "as part of NPC short descriptions.\n"
            "Possible values are: on, off",
        "suppress message": 1,
        "wizard only": 0
    ]),]);

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "General";
        addCommandTemplate("set [-p ##Value##] [-v ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        string parameter = 0;
        string value = 0;
        
        if (sizeof(regexp(({ command }), "^set .*-p *[^-]+( -.*|$)")))
        {
            parameter = regreplace(command, "^set .*-p *([^-]+)( -.*|$)", "\\1");
            command = regreplace(command, "(^set *.*)( -p *[^-]+)( -.*|$)", "\\1\\3");
        }
        if (sizeof(regexp(({ command }), "^set .*-v *.+( -p.*|$)")))
        {
            value = regreplace(command, "^set .*-v *(.+)( -p.*|$)", "\\1");
        }

        if (member(parametersToFunction, parameter) && parameter && value &&
           ((member(filter(m_indices(parametersToFunction), (: !$2[$1]["wizard only"] :), 
               parametersToFunction), parameter) > -1) || initiator->hasExecuteAccess("set")))
        {
            ret = 1;
            call_other(initiator, parametersToFunction[parameter]["method"], value);
            
            if (!member(parametersToFunction[parameter], "suppress message"))
            {
                tell_object(initiator, sprintf("You have set your '%s' to '%s'.\n",
                    parameter, value));
            }
        }
        else
        {
            notify_fail(sprintf("The '%s' parameter is not valid.\n", parameter || "???"));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Set various player-controlled game parameters.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    
    switch (parsedFlag)
    {
        case "-p":
        {
            ret = "This flag allows a user to specify the parameter "
                "they wish to set.\nIt must be used in conjunction with the -v "
                "flag. Possible parameters are:\n\n";

            string *parameters = sort_array(m_indices(parametersToFunction), 
                (: $1 > $2 :));

            if (!this_player() || !this_player()->hasExecuteAccess("set"))
            {
                parameters -= filter(m_indices(parametersToFunction),
                    (: $2[$1]["wizard only"] :), parametersToFunction);
            }

            foreach(string parameter in parameters)
            {
                string paramDescription = format(
                    parametersToFunction[parameter]["description"], 44);

                string *paramSplitDescription = explode(paramDescription, "\n");

                ret += sprintf("%-20s - %s\n", parameter, 
                    paramSplitDescription[0]);
                if (sizeof(paramSplitDescription) > 1)
                {
                    foreach(string descriptionLine in paramSplitDescription[1..])
                    {
                        ret += sprintf("%23s%s\n", "", descriptionLine);
                    }
                }
            }
            break;
        }
        case "-v":
        {
            ret = "This option will set the value for the specified parameter.\n"
                "It must be used in conjunction with the -p flag.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Set allows a player to set various configuration parameters "
        "for their character. This includes color support, unicode support, "
        "and descriptions. It also allows a player to block messages coming from "
        "individuals, channels, or shout and can be used to  "
        "set a 'busy' flag - a temporary block of directed (tell) "
        "messages.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, reply, guild, and shout";
}
