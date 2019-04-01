//******************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Social";
        addCommandTemplate("say [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
        addCommandTemplate("' [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getDictionary()
{
    return load_object("/lib/dictionaries/languageDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void speakMessage(string message, string messageTemplate,
    object initiator, object target, string language)
{
    message = regreplace(message, "(say|') *(.*)", "\\2", 1);

    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator))
    {
        object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

        object *characters = filter(all_inventory(environment(initiator)),
            (: $1->isRealizationOfLiving() :));

        foreach(object person in characters)
        {
            if (person && objectp(person))
            {
                string newMessage = message;
                if (language)
                {
                    newMessage = getDictionary()->applyLanguageSkillToReceivedMessage(language, message,
                        person, initiator);
                }
                string parsedMessage = regreplace(messageTemplate, "##Message##", newMessage);

                if (person == initiator)
                {
                    parsedMessage = parseTemplate(parsedMessage, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(parsedMessage, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(parsedMessage, "other",
                        initiator, target);
                }
                if (!person->blocked(initiator))
                {
                    tell_object(person, configuration->decorate(
                        format(parsedMessage, 78), "message", "say",
                        person->colorConfiguration()));
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    string messageTemplate = "##InitiatorName## ##Adverb##"
        "##Infinitive::verb####TargetPreposition####TargetName##"
        "##LanguagePreposition####Language##, `##Message##'";

    if (canExecuteCommand(command))
    {
        ret = 1;
        object targetObj = 0;
        string language = 0;

        if (sizeof(regexp(({ command }), "-v(erb)* [A-Za-z]+")))
        {
            string verb = regreplace(command, ".*-v(erb)* ([A-Za-z]+) .*", "\\2", 1);
            command = regreplace(command, "-v(erb)* ([A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "::verb", "::" + verb);
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "::verb", "::say");
        }

        if (sizeof(regexp(({ command }), "-a(dverb)* [A-Za-z]+")))
        {
            string adverb = regreplace(command, ".*-a(dverb)* ([A-Za-z]+) .*", "\\2 ", 1);
            command = regreplace(command, "-a(dverb)* ([A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "##Adverb##", adverb);
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##Adverb##", "");
        }

        if (sizeof(regexp(({ command }), "-t(arget)* '*[A-Za-z]+")))
        {
            string target = regreplace(command, ".*-t(arget)* ([A-Za-z]+|'[^']+') .*", "\\2", 1);
            target = regreplace(target, "'([^']+)'", "\\1", 1);
            targetObj = present(target, environment(initiator));
            command = regreplace(command, "-t(arget)* ([A-Za-z]+)", "", 1);
            command = regreplace(command, "-t(arget)* ('[A-Za-z ]+')", "", 1);

            if (!targetObj)
            {
                messageTemplate = regreplace(messageTemplate, "##TargetName##", target);
            }
            messageTemplate = regreplace(messageTemplate, "##TargetPreposition##", " to ");
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##TargetName##", "");
            messageTemplate = regreplace(messageTemplate, "##TargetPreposition##", "");
        }

        if (sizeof(regexp(({ command }), "-l(anguage)* (high elven|[A-Za-z]+)")))
        {
            language = regreplace(command, ".*-l(anguage)* (high elven|[A-Za-z]+) .*", "\\2", 1);
            command = regreplace(command, "-l(anguage)* (high elven|[A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "##Language##", 
                getDictionary()->getSpokenLanguage(language, initiator));
            messageTemplate = regreplace(messageTemplate, "##LanguagePreposition##", " in ");
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##Language##", "");
            messageTemplate = regreplace(messageTemplate, "##LanguagePreposition##", "");
        }

        // This will kill the other flags
        if (sizeof(regexp(({ command }), "(say|') -[A-Za-z]+")))
        {
            string flag = regreplace(command, "(say|') (-[A-Za-z]+).*", "\\2", 1);
            tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
        }
        else
        {
            speakMessage(command, messageTemplate, initiator, targetObj, language);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return configuration->decorate("<Message to speak>",
        "wildcard", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send a message to everyone in your environment";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-v":
        {
            ret = "This option will replace the verb displayed as part of "
                "the 'say' message. For example:\n\t" +
                configuration->decorate("> say -v grumble I'm grumpy!\n",
                    "message", "say", colorConfiguration) +
                configuration->decorate("\tYou grumble, `I'm grumpy!'\n",
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) + 
                configuration->decorate("\tBob grumbles, `I'm grumpy!'\n",
                        "help display", "say", colorConfiguration);
            break;
        }
        case "-a":
        {
            ret = "This option will add an adverb to "
                "the 'say' message. For example:\n\t" +
                configuration->decorate("> say -a sarcastically You're my "
                    "hero!\n", "message", "say", colorConfiguration) +
                configuration->decorate("\tYou sarcastically say, `You're "
                    "my hero!'\n", "help display", "say", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob sarcastically says, `You're "
                    "my hero!'\n", "help display", "say", colorConfiguration); 
            break;
        }
        case "-l":
        {
            ret = "This option will translate the message you wish to say into "
                "the given language - or at least attempt to do so. Your skill "
                "in the target language will determine whether or not it is "
                "translated appropriately or becomes gibberish. Those in the "
                "environment will then use their skill to translate the message "
                "back to English. For example if you have no skill in a "
                "language, you might see:\n\t" +
                configuration->decorate("> say -l orcish I should say "
                    "something nice.\n", "message", "say", colorConfiguration) +
                configuration->decorate("\tYou say in complete gibberish, "
                    "`Blarg nukuleve zog forgla bup'\n",
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob says in complete gibberish, "
                    "`Blarg nukuleve zog forgla bup'\n",
                    "help display", "say", colorConfiguration) +

                configuration->decorate("Meanwhile, if you do know a language "
                    "you might see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("> say -l elven I should say "
                    "something nice.\n", "message", "say", colorConfiguration) +
                configuration->decorate("\tYou say in elven, `I should "
                    "say something nice.'\n",
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Other users that have a high skill in "
                    "elven would see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob says in elven, `I should "
                    "say something nice.'\n",
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Other users that have no skill in "
                    "elven would see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob says in elven, `Naur wu "
                    "simildin welana loomen'\n",
                    "help display", "say", colorConfiguration) +

                configuration->decorate("It is important to note that knowledge "
                    "of a language is a range and, so too, is one's ability "
                    "to speak and translate it. You will go from being able to "
                    "speak/understand nothing to brokenly speaking or "
                    "partially understanding all the way through being "
                    "completely fluent.\n",
                    "text", "help", colorConfiguration);
            break;
        }
        case "-t":
        {
            ret = "This option will allow you to speak a message to a specific "
                "target. For example:\n\t" +
                configuration->decorate("> say -t Fred Hi Fred!\n",
                    "message", "say", colorConfiguration) +
                configuration->decorate("\tYou say to Fred, `Hi Fred!'\n", 
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Fred would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob says to you, `Hi Fred!'\n",
                    "help display", "say", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob says to Fred, `Hi Fred!'\n", 
                    "help display", "say", colorConfiguration);
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Say allows a player to display a message to all players "
        "located in the same room where he or she is standing. The character ' "
        "can be used as an abbreviation for say to save time. Interactions "
        "with players can be blocked using the 'block player' setting.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, whisper, reply, shout, and set";
}
