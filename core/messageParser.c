//*****************************************************************************
// Class: messageParser
// File Name: messageParser.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
private string MaterialAttributes = "lib/modules/materialAttributes.c";

/////////////////////////////////////////////////////////////////////////////
private nomask string formatText(string text, int colorInfo, object viewer)
{
    return color(viewer->query("term"), viewer, colorInfo, format(text, 78));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidAttacker(object attacker)
{
    return (attacker && objectp(attacker) && 
            (member(inherit_list(attacker), MaterialAttributes) > -1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getName(object actor, int isSecondPerson)
{
    string ret = "you";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = capitalize(actor->RealName());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getObjective(object actor, int isSecondPerson)
{
    string ret = "you";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = actor->Objective();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getSubjective(object actor, int isSecondPerson)
{
    string ret = "you";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = actor->Pronoun();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getPossessiveName(object actor, int isSecondPerson)
{
    string ret = "your";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = sprintf("%s's", actor->Name());
    }
    return ret;
}

private nomask varargs string getPossessive(object actor, int isSecondPerson)
{
    string ret = "your";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = actor->Possessive();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getReflexive(object actor, int isSecondPerson)
{
    string ret = "yourself";
    if(!isSecondPerson && isValidAttacker(actor))
    {
        ret = actor->Reflexive();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getBodyPart(object actor)
{
    // This breaks down for weird creatures.... need to fix eventually.
    string *parts = ({ "head", "torso", "mouth", "stomach", "abdomen", "chest", "back", "leg", "neck" });

    return parts[random(sizeof(parts))];
}

/////////////////////////////////////////////////////////////////////////////
private nomask string extractVerb(string match)
{
    string ret = "ERROR";
    string query = regreplace(match, "##(.*)##", "\\1");
    string *arguments = explode(query, "::");

    if((sizeof(arguments) > 1) && arguments[1] && stringp(arguments[1]))
    {
        ret = arguments[1];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string verbSecondPerson(string match)
{
    return extractVerb(match);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getSingularThirdPersonVerb(string verb)
{
    // This will be imperfect, only converting regular forms right now.
    // TODO might include adding irregulars.
    string ret = verb;
    
    ret = regreplace(ret, "(s|ch|sh|x|z|dg|o)$", "\\1e");
    ret = regreplace(ret, "([^aeiou])y$", "\\1ie");
    ret += "s";
    return ret;
}    

/////////////////////////////////////////////////////////////////////////////
private nomask string verbThirdPerson(string match)
{
    return getSingularThirdPersonVerb(extractVerb(match));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parseSimileDictionary(string message, object messageItem)
{
    // ##SimileDictionary## - random word from the simile dictionary
    string ret = message;
    if(message && stringp(message) && messageItem && objectp(messageItem) && 
       function_exists("getRandomSimile", messageItem))
    {
        string tmpMsg;
        // Looping allows each instance of ##SimileDictionary to be different
        do
        {
            tmpMsg = ret;
            ret = regreplace(ret, "##SimileDictionary##", 
                messageItem->getRandomSimile());
        } while(tmpMsg != ret);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parseVerbDictionary(string message,
    string stringToReplace, object messageItem)
{
    // ##<stringToReplace>## - random word from a verb dictionary 
    // This is converted into ##Infinitive::verb## for parsing
    // with parseVerbs
    string ret = message;
    if(message && stringp(message) && messageItem && objectp(messageItem) && 
       function_exists("getRandomVerb", messageItem))
    {
        string tmpMsg;
        // Looping allows each instance of ##SimileDictionary to be different
        do
        {
            tmpMsg = ret;
            ret = regreplace(ret, sprintf("##%s##", stringToReplace), 
                messageItem->getRandomVerb());
        } while(tmpMsg != ret);
    }
    return ret;  
}

/////////////////////////////////////////////////////////////////////////////
nomask string parseVerbs(string message, int isSecondPerson)
{
    // ##Infinitive::verb## - replaced with 2nd person or 3rd person form
    return regreplace(message, "##Infinitive::[a-z]+##",
            (isSecondPerson ? #'verbSecondPerson : #'verbThirdPerson), 1);  
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parseTargetInfo(string message, string typeOfTarget,
    object target, int isSecondPerson)
{
    string ret = message;
    // ##<typeOfTarget>Name## - target's name
    // ##<typeOfTarget>Possessive[::Name]## - target's possessive / your
    // ##<typeOfTarget>Objective## - target's objective / you
    // ##<typeOfTarget>Subjective## - target's subjective/pronoun / you

    if(isValidAttacker(target))
    {
        // What this lacks in elegance, it more than makes up for in laziness
        ret = regreplace(ret, sprintf("##%sName##", typeOfTarget), 
            getName(target, isSecondPerson), 1);
        ret = regreplace(ret, sprintf("##%sObjective##", typeOfTarget), 
            getObjective(target, isSecondPerson), 1);
        ret = regreplace(ret, sprintf("##%sSubjective##", typeOfTarget), 
            getSubjective(target, isSecondPerson), 1);
        ret = regreplace(ret, sprintf("##%sPossessive::Name##", typeOfTarget), 
            getPossessiveName(target, isSecondPerson), 1);
        ret = regreplace(ret, sprintf("##%sPossessive##", typeOfTarget), 
            getPossessive(target, isSecondPerson), 1);
        ret = regreplace(ret, sprintf("##%sReflexive##", typeOfTarget), 
            getReflexive(target, isSecondPerson), 1);        
        ret = regreplace(ret, "##BodyPart##", getBodyPart(target), 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parseTargetWeapon(string message, string typeOfTarget,
    object weapon)
{
    string ret = message;

    if (objectp(weapon))
    {
        string weaponType = weapon->query("weapon type") ? weapon->query("weapon type") : "";
        ret = regreplace(ret, sprintf("##%sWeapon##", typeOfTarget),
            weaponType, 1);
    }
    // TODO
    // ##AttackerWeapon## - type of attacker's weapon (longsword, short sword,
    //   claymore...)
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string capitalizeSentences(string message)
{
    string ret = regreplace(message, "^[a-z]", #'upper_case, 1);
    ret = regreplace(ret, "[.!?] [a-z]", #'upper_case, 1);
    ret = regreplace(ret, "  ", " ");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string parseEfun(string match)
{
    string ret = "ERROR";
    // This is of the form efun::type::(path|name|this)[::function]
    // type can be any of: filename, target, this
    // path is a file path, name is the name of target, this is a "don't care"
    // function is a method on the called object. The method MUST return a
    // string. 
    string *arguments = explode(match, "::");
    if(sizeof(arguments) > 2)
    {
        switch(arguments[0])
        {
            case "##call_other":
            {
                switch(arguments[1])
                {
                    case "filename":
                    case "file":
                    {
                        if(file_size(arguments[2]) > 0)
                        {
                            object objFromFile = load_object(arguments[2]);
                            if(objFromFile && arguments[3] && 
                               function_exists(arguments[3], objFromFile))
                            {
                                ret = call_other(objFromFile, arguments[3]);
                            }
                        }
                        break;
                    }
                    case "target":
                    {
                        if(arguments[2] && this_player() && 
                           environment(this_player()) &&
                           present(arguments[2], environment(this_player())))
                        {
                            ret = call_other(present(arguments[2],
                                  environment(this_player())), arguments[3]);
                        }
                        break;
                    }
                    case "this":
                    {
                        if(arguments[3])
                        {
                            ret = call_other(this_object(), arguments[3]);
                        }
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            case "##read_file":
            {
                if((arguments[1] == "filename") &&file_size(arguments[2]) > 0)
                {
                    ret = read_file(arguments[2]);
                } 
                break;
            }            
            default:
            {
                break;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string parseEfunCall(string message)
{
    return regreplace(message,
        "##([^:]+)::(file|target|this)::([^:]+)::([a-zA-Z0-9_])+",
        #'parseEfun,1);
}


