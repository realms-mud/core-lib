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
        CommandType = "Social";
        addCommandTemplate("shout [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getDictionary()
{
    return load_object("/lib/dictionaries/languageDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void shoutMessage(string message, string messageTemplate,
    object initiator, string language)
{
    message = regreplace(message, "shout *(.*)", "\\1", 1);

    object *targets = filter(users(), (: return !$1->isEarmuffed(); :));
    if (member(targets, initiator) < 0)
    {
        // Add initiator if they're earmuffed.
        targets += ({ initiator });
    }

    object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

    foreach(object target in targets)
    {
        string newMessage = message;
        if (language)
        {
            newMessage = getDictionary()->applyLanguageSkillToReceivedMessage(language, message,
                target, initiator);
        }
        string parsedMessage = regreplace(messageTemplate, "##Message##", newMessage);

        if (target == initiator)
        {
            parsedMessage = parseTemplate(parsedMessage, "initiator", initiator,
                target);
        }
        else
        {
            parsedMessage = parseTemplate(parsedMessage, "other",
                initiator, target);
        }
        if (!target->blocked(initiator))
        {
            tell_object(target, configuration->decorate(
                format(parsedMessage, 78), "message", "shout",
                target->colorConfiguration()));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    string messageTemplate = "##InitiatorName## ##Adverb##"
        "##Infinitive::verb####LanguagePreposition##"
        "##Language##, `##Message##'";

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
            messageTemplate = regreplace(messageTemplate, "::verb", "::shout");
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
        if (sizeof(regexp(({ command }), "(shout|') -[A-Za-z]+")))
        {
            string flag = regreplace(command, "(shout|') (-[A-Za-z]+).*", "\\2", 1);
            tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
        }
        else
        {
            shoutMessage(command, messageTemplate, initiator, language);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return "\x1b[0;31;1m<Message to speak>\x1b[0m";
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send a message to everyone on the mud";
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
                "the 'shout' message. For example:\n\t" +
                configuration->decorate("> shout -v grumble I'm grumpy!\n",
                    "message", "shout", colorConfiguration) +
                configuration->decorate("\tYou grumble, `I'm grumpy!'\n",
                    "help display", "shout", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) + 
                configuration->decorate("\tBob grumbles, `I'm grumpy!'\n",
                        "help display", "shout", colorConfiguration);
            break;
        }
        case "-a":
        {
            ret = "This option will add an adverb to "
                "the 'shout' message. For example:\n\t" +
                configuration->decorate("> shout -a sarcastically You're my "
                    "hero!\n", "message", "shout", colorConfiguration) +
                configuration->decorate("\tYou sarcastically shout, `You're "
                    "my hero!'\n", "help display", "shout", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob sarcastically shouts, `You're "
                    "my hero!'\n", "help display", "shout", colorConfiguration); 
            break;
        }
        case "-l":
        {
            ret = "This option will translate the message you wish to shout into "
                "the given language - or at least attempt to do so. Your skill "
                "in the target language will determine whether or not it is "
                "translated appropriately or becomes gibberish. Those in the "
                "environment will then use their skill to translate the message "
                "back to English. For example if you have no skill in a "
                "language, you might see:\n\t" +
                configuration->decorate("> shout -l orcish I should shout "
                    "something nice.\n", "message", "shout", colorConfiguration) +
                configuration->decorate("\tYou shout in complete gibberish, "
                    "`Blarg nukuleve zog forgla bup'\n",
                    "help display", "shout", colorConfiguration) +
                configuration->decorate("Other users would then see:\n",
                    "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob shouts in complete gibberish, "
                    "`Blarg nukuleve zog forgla bup'\n",
                    "help display", "shout", colorConfiguration) +

                configuration->decorate("Meanwhile, if you do know a language "
                    "you might see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("> shout -l elven I should shout "
                    "something nice.\n", "message", "shout", colorConfiguration) +
                configuration->decorate("\tYou shout in elven, `I should "
                    "shout something nice.'\n",
                    "help display", "shout", colorConfiguration) +
                configuration->decorate("Other users that have a high skill in "
                    "elven would see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob shouts in elven, `I should "
                    "shout something nice.'\n",
                    "help display", "shout", colorConfiguration) +
                configuration->decorate("Other users that have no skill in "
                    "elven would see:\n", "message", "soul", colorConfiguration) +
                configuration->decorate("\tBob shouts in elven, `Naur wu "
                    "simildin welana loomen'\n",
                    "help display", "shout", colorConfiguration) +

                configuration->decorate("It is important to note that knowledge "
                    "of a language is a range and, so too, is one's ability "
                    "to speak and translate it. You will go from being able to "
                    "speak/understand nothing to brokenly speaking or "
                    "partially understanding all the way through being "
                    "completely fluent.\n",
                    "text", "help", colorConfiguration);
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Shout allows a player to display a message to all players "
        "in the game. Players can block shouts using the earmuffs "
        "setting.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: tell, whisper, reply, say, and set";
}
