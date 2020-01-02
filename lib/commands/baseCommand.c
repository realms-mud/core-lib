//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string MaterialAttributes = "lib/modules/materialAttributes.c";
private string MessageParser = "/lib/core/messageParser.c";

protected string *commands = ({});
protected int SplitCommands;
protected string CommandType = "general";
protected object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

protected int TargetEnvironment = 2;
protected int TargetInventory = 1;
protected int TargetBoth = 3;

/////////////////////////////////////////////////////////////////////////////
public nomask string *commandList()
{
    return commands + ({});
}

/////////////////////////////////////////////////////////////////////////////
private nomask string prepCommandRegExp(string command)
{
    string ret = regreplace(command, "\\] *\\[", ")*( ", 1);
    ret = regreplace(ret, " \\[(.+)\\]", "( \\1)\*", 1);

    return "^" + ret + "$";
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string commandRegExp(string commandToParse)
{
    string ret = 0;

    if(sizeof(commands))
    {
        ret = "(";

        if (commandToParse && (member(commands, commandToParse) > -1))
        {
            ret += prepCommandRegExp(commandToParse);
        }
        else
        {
            foreach(string command in commands)
            {
                if (sizeof(ret) > 1)
                {
                    ret += "|";
                }
                ret += prepCommandRegExp(command);
            }
        }
        ret += ")";

        ret = regreplace(ret, "##(Target|Environment|Item|Value)##", ".+", 1);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canExecuteCommand(string passedCommand)
{
    int ret = 0;

    if(passedCommand && stringp(passedCommand))
    {
        string commandRegexp;
        if (SplitCommands)
        {
            foreach(string command in commands)
            {
                commandRegexp = commandRegExp(command);
                if (commandRegexp)
                {
                    ret = sizeof(regexp(({ passedCommand }), commandRegexp));
                    if (ret)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            commandRegexp = commandRegExp();

            if (commandRegexp)
            {
                ret = sizeof(regexp(({ passedCommand }), commandRegexp));
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string commandString(string passedCommand)
{
    string ret = 0;

    if(sizeof(commands))
    {
        foreach(string command in commands)
        {
            string commandRegexp = prepCommandRegExp(command);
            string commandCheck = regreplace(commandRegexp, "##(Target|Environment|Item|Value)##", ".+", 1);

            if (sizeof(regexp(({ passedCommand }), commandCheck)))
            {
                ret = regreplace(commandRegexp, "##(Target|Environment|Item|Value)##", "", 1);
                ret -= "$";
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs object getTarget(object owner, string command, 
    int flags)
{
    object ret = 0;
    string template = commandString(command);

    if (!flags)
    {
        flags = TargetBoth;
    }

    if (command && stringp(command) && template && stringp(template) &&
        environment(owner))
    {
        string *targetId = regexplode(command, template);

        if (sizeof(targetId) == 3)
        {
            string target = lower_case(targetId[2]);
            ret = ((flags & TargetEnvironment) ? 
                present(target, environment(owner)) : 0) || 
                ((flags & TargetInventory) ? present(target, owner) : 0);

            if (!ret && environment(owner)->isEnvironmentalElement(target))
            {
                ret = environment(owner)->getEnvironmentalElement(target);
            }
            else if(!ret && (this_object()->query("scope") == "targeted") &&
                (target == ""))
            {
                ret = owner;
            }
        }
    }

    if ((ret == owner) && this_object()->query("damage type") &&
        !this_object()->query("is beneficial"))
    {
        ret = owner->getTargetToAttack();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string getTargetString(object owner, string command)
{
    string ret = 0;
    string template = commandString(command);

    if (command && stringp(command) && template && stringp(template))
    {
        string *targetId = regexplode(command, template);

        if (sizeof(targetId) == 3)
        {
            ret = targetId[2];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int execute(string command, object initiator)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addCommandTemplate(string command)
{
    int ret = 0;

    if (member(commands, command) == -1)
    {
        commands += ({ command });
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string commandType()
{
    return CommandType;
}

/////////////////////////////////////////////////////////////////////////////
private nomask object messageParser()
{
    return load_object(MessageParser);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidLiving(object livingCheck)
{
    return (livingCheck && objectp(livingCheck) && 
            (member(inherit_list(livingCheck), MaterialAttributes) > -1));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string parseTemplate(string template, string perspective,
                                    object initiator, object target)
{
    string message = template;
    // ##Infinitive::verb##
    // ##InitiatorName## - Initiator's name
    // ##InitiatorPossessive[::Name]## - Initiator possessive / your / Name's
    // ##InitiatorObjective## - Initiator's objective / you
    // ##InitiatorReflexive## - Initiator's reflexive pronoun / yourself
    // ##InitiatorSubjective## - Initiator's subjective pronoun / you
    // ##Target[NPOS]## - Target's (one of above 4)
    // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
    //   chop/chops)
    // ##SimileDictionary## - random word from the simile dictionary

    // dictionary calls must be done first!
    int isSecondPerson = (perspective == "initiator");
    
    if(initiator && objectp(initiator))
    {
        message = messageParser()->parseSimileDictionary(message, initiator);
        message = messageParser()->parseVerbDictionary(message, 
            "HitDictionary", initiator);
            
        message = messageParser()->parseVerbs(message, isSecondPerson);
    }
    
    if(isValidLiving(initiator))
    {
        message = messageParser()->parseTargetInfo(message, "Initiator", 
            initiator, isSecondPerson);

        object weapon =
            initiator->equipmentInSlot("wielded primary");

        if (weapon)
        {
            message = messageParser()->parseTargetWeapon(message, "Initiator",
                weapon);
        }
    }

    if(isValidLiving(target))
    {    
        isSecondPerson = (perspective == "target");
        message = messageParser()->parseTargetInfo(message, "Target", 
            target, isSecondPerson);      
    }
    
    message = messageParser()->capitalizeSentences(message);
    return message;    
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void displayMessage(string message, object initiator,
    object target)
{
    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator))
    {
        object *characters = filter(all_inventory(environment(initiator)),
            (: $1->isRealizationOfLiving() :));

        foreach(object person in characters)
        {
            if (person && objectp(person))// && interactive(person))
            {
                string parsedMessage;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(message, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(message, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(message, "other",
                        initiator, target);
                }
                tell_object(person, configuration->decorate(
                    format(parsedMessage, 78), "text", "command",
                    person->colorConfiguration()));
            }
        }
    }
} 

/////////////////////////////////////////////////////////////////////////////
protected nomask void displayMessageToSelf(string message, object initiator)
{
    if (initiator && objectp(initiator))
    {
        string parsedMessage;

        parsedMessage = parseTemplate(message, "initiator", initiator,
            initiator);

        tell_object(initiator, configuration->decorate(
            format(parsedMessage, 78), "text", "command",
            initiator->colorConfiguration()));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string usageDetails(string displayCommand, string colorConfiguration)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string options(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string copyright(string colorConfiguration)
{
    return configuration->decorate("\n\nCopyright\n", "heading", "help",
            colorConfiguration) +
        configuration->decorate("\tCopyright (C) 1991-2020 Allen "
            "Cummings. For additional licensing\n\tinformation, see ",
            "text", "help", colorConfiguration) +
        configuration->decorate("http://realmsmud.org/license/\n",
            "url", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayUsageDetails(string displayCommand,
    string colorConfiguration, int useUnicode)
{
    string ret = "";

    string details = usageDetails(displayCommand, colorConfiguration);

    if (details)
    {
        ret = details;
    }
    else if (sizeof(commands))
    {
        string *commandText = ({});
        foreach(string command in commands)
        {
            string currentCommand = regreplace(command, "\\[\\.\\*\\]", 
                wildcardMeaning(colorConfiguration), 1);

            currentCommand = regreplace(currentCommand, "[[][(]([^|]+)[|]([^]]+)[)][+]", "[\\1] [\\2", 1);
            currentCommand = format(regreplace(currentCommand, "\\|", "", 1), 66);
            currentCommand = regreplace(currentCommand, "([^#]*)##([^#]+)##([^#]*)", 
                configuration->decorate("\\1", "text", "help", colorConfiguration) +
                configuration->decorate("<\\2>", "parameter", "help", colorConfiguration) +
                configuration->decorate("\\3", "text", "help", colorConfiguration), 1);
            if (!sizeof(regexp(({ currentCommand }), "\x1b")))
            {
                currentCommand = configuration->decorate(currentCommand,
                    "text", "help", colorConfiguration);
            }
            commandText += ({ regreplace(currentCommand, "\n", "\n\t\t", 1) });
        }
        ret = "\t" + implode(commandText, "\n\t") + "\n";
    }

    return configuration->decorate("\nSyntax\n", "heading", "help", 
        colorConfiguration) + ret;
}

/////////////////////////////////////////////////////////////////////////////
public string displaySynopsis(string displayCommand,
    string colorConfiguration, int useUnicode)
{
    return configuration->decorate("Synopsis\n", "heading", "help",
            colorConfiguration) +
        configuration->decorate(format(sprintf("\t%s - %s\n", displayCommand,
            synopsis(displayCommand, colorConfiguration)), 75),
            "text", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public string displayDescription(string displayCommand,
    string colorConfiguration, int useUnicode)
{
    return configuration->decorate("Description\n", "heading", "help",
            colorConfiguration) +
        configuration->decorate(description(displayCommand + "\n", 
            colorConfiguration), "text", "help", colorConfiguration); 
}

/////////////////////////////////////////////////////////////////////////////
private string formatFlag(string flag, string colorConfiguration)
{
    string ret = regreplace(flag, "[[()]*\\]*", "", 1);
    return regreplace(ret, "(.*)##([^#]+)##(.*)",
        configuration->decorate("\\1", "heading", "help", colorConfiguration) +
        configuration->decorate("<\\2>", "parameter", "help", colorConfiguration) +
        configuration->decorate("\\3", "heading", "help", colorConfiguration), 1);
}

/////////////////////////////////////////////////////////////////////////////
public string displayOptions(string displayCommand,
    string colorConfiguration, int useUnicode)
{
    string ret = "";
    if (sizeof(commands) && sizeof(regexp(({ commands[0] }), " [[]*[(-]+[a-zA-Z]")))
    {
        string commandBlueprint = regreplace(commands[0], "^([^-[]+ +)(.*)", "\\2");
        commandBlueprint = regreplace(commandBlueprint, "[[][(]([^|]+)[|]([^]]+)[)][+]", "[\\1] [\\2", 1);
        string *options = explode(commandBlueprint, " [") - ({ ".*]" });

        string *optionList = ({});
        foreach(string option in options)
        {
            string shorthand = formatFlag(regreplace(option, 
                "\\[*(.+)\\([^)]+\\)([^]]*)[]]$", "\\1\\2"), 
                colorConfiguration);

            string verbose = formatFlag(regreplace(option, 
                "\\[*(.+)\\(([^|]+)\\|\\)([^]]*)[]]$", "\\1\\2\\3"), 
                colorConfiguration);

            string displayFlag = shorthand;
            if (shorthand != verbose)
            {
                displayFlag += ", " + verbose;
            }
            displayFlag = "    " + displayFlag;

            if (sizeof(regexp(({ displayFlag }),  "-")))
            {
                optionList += ({ "\n" + displayFlag + "\n\t" + 
                    configuration->decorate(regreplace(format(
                        flagInformation(shorthand, colorConfiguration), 78), 
                        "\n", "\n\t", 1),
                        "text", "help", colorConfiguration) });
            }
        }
        ret = implode(optionList, "");
    }
    else
    {
        ret = configuration->decorate(
            "\tThis command does not have any options.\n",
            "text", "help", colorConfiguration);
    }

    return configuration->decorate("\nOptions\n", "heading", "help",
            colorConfiguration) + ret + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public string displayNotes(string displayCommand,
    string colorConfiguration, int useUnicode)
{
    return configuration->decorate("Notes\n\t", "heading", "help",
            colorConfiguration) +
        configuration->decorate(notes(displayCommand + "\n",
            colorConfiguration), "text", "help", colorConfiguration) +
        copyright(colorConfiguration);
}
