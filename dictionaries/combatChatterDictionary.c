//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private string MaterialAttributes = "lib/modules/materialAttributes.c";
private string MessageParser = "/lib/core/messageParser.c";

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
protected nomask string formatText(string text, int colorInfo, object viewer)
{
    return color(viewer->query("term"), viewer, colorInfo, format(text, 78));
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
private nomask varargs void displayMessage(string message, object initiator,
    object target)
{
    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator) && message)
    {
        foreach(object person in all_inventory(environment(initiator)))
        {
            if (person && objectp(person))
            {
                string parsedMessage;
                int colorInfo = 8;
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
                tell_object(person, formatText(parsedMessage, colorInfo,
                    person));
            }
        }
    }
} 

/////////////////////////////////////////////////////////////////////////////
public nomask void displayCombatChatter(int damage, object attacker, 
    object defender, int alwaysDisplay)
{
    if (objectp(attacker) && objectp(defender))
    {
        if (damage)
        {
            displayMessage(attacker->speakCombatChatter("offensive hit", defender, alwaysDisplay),
                attacker, defender);

            if (!defender->isDead())
            {
                displayMessage(defender->speakCombatChatter("defensive hit", defender, alwaysDisplay),
                    defender, attacker);
            }
            else
            {
                displayMessage(defender->speakCombatChatter("death", defender, alwaysDisplay),
                    defender, attacker);
                displayMessage(attacker->speakCombatChatter("kill", attacker, alwaysDisplay),
                    attacker, defender);
            }
        }
        else
        {
            displayMessage(attacker->speakCombatChatter("offensive miss", attacker, alwaysDisplay),
                attacker, defender);
            displayMessage(defender->speakCombatChatter("defensive miss", defender, alwaysDisplay),
                defender, attacker);
        }
    }
}
