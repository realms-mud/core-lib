//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/materialAttributes.h"

/////////////////////////////////////////////////////////////////////////////
static nomask string *validMaterialAttributes()
{
    return ({ "name", "gender", "aliases", "short", "long", "size", "title",
              "pretitle", "message in", "message out", "message home",
              "message clone", "magical message in", "magical message out",
              "age", "money", "invisibility" });
}

/////////////////////////////////////////////////////////////////////////////
public varargs string Name(string newName)
{
    if(newName && (!name || !function_exists("isPlayer", this_object())))
    {
        name = newName;
    }

    return ghost ? "some mist" : capitalize(name);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string RealName()
{
    return name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string creationDate()
{
    return whenCreated;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string savedLocation()
{
    return location;
}

/////////////////////////////////////////////////////////////////////////////
public varargs int Gender(int newGender)
{
    if(newGender)
    {
        if(intp(newGender) && (newGender < 3) && (newGender > -1))
        {
            gender = newGender;
        }
        else
        {
            raise_error("materialAttributes: gender can only be set to "
                "0, 1, or 2.\n");
        }
    }
    
    return gender;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string pronounByType(string type)
{
    string ret = 0;
    if(member(({ 0, 1, 2}), gender) < 0)
    {
        gender = 0;
    }
    
    if(member(m_indices(genderPronouns[gender]), type) > -1)
    {
        ret = genderPronouns[gender][type];
    }
    else
    {
        raise_error("materialAttributes: Illegal gender pronoun request.\n");
    }
    return ret;
}


/////////////////////////////////////////////////////////////////////////////
public string GenderDesc()
{
    // Obviously not really a pronoun... laziness intercedes and makes this the
    // correct way to do this despite the name.
    return pronounByType("name");
}

/////////////////////////////////////////////////////////////////////////////
public string Pronoun()
{ 
    return pronounByType("nominative");
}

/////////////////////////////////////////////////////////////////////////////
public string Objective()
{ 
    return pronounByType("dative");
}

/////////////////////////////////////////////////////////////////////////////
public string Possessive()
{ 
    return pronounByType("genitive");
}

/////////////////////////////////////////////////////////////////////////////
public string Reflexive()
{ 
    return pronounByType("reflexive");
}

/////////////////////////////////////////////////////////////////////////////
public varargs int Invisibility(int isInvis)
{
    // Invisibility is going to be overhauled.
    // For any but wizards, this is a boolean value -
    // you're either invisible or not. 
    // For wizards, this needs to be overloaded.
    if(isInvis && intp(isInvis))
    {
        invisibility = !invisibility;
    }
    
    return invisibility;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int Ghost(int isGhost)
{
    if(isGhost && intp(isGhost))
    {
        ghost = !ghost;
    }
    return ghost;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string MessageIn(string msg)
{
    if(msg && stringp(msg))
    {
        messageIn = msg;
    }
    else if(!messageIn || (messageIn == ""))
    {
        messageIn = "##Infinitive::arrive##";
    }
    return messageIn;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string MessageOut(string msg)
{
    if(msg && stringp(msg))
    {
        messageOut = msg;
    }
    else if (!messageOut || (messageOut == ""))
    {
        messageOut = "##Infinitive::leave##";
    }
    return messageOut;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string MagicalMessageIn(string msg)
{
    if(msg && stringp(msg))
    {
        magicalMessageIn = msg;
    }
    else if (!magicalMessageIn || (magicalMessageIn == ""))
    {
        magicalMessageIn = "##Infinitive::appear## in a puff of smoke";
    }
    return magicalMessageIn;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string MagicalMessageOut(string msg)
{
    if(msg && stringp(msg))
    {
        magicalMessageOut = msg;
    }
    else if (!magicalMessageOut || (magicalMessageOut == ""))
    {
        magicalMessageOut = "##Infinitive::vanish## in a puff of smoke";
    }
    return magicalMessageOut;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string MessageHome(string msg)
{
    if(msg && stringp(msg))
    {
        messageHome = msg;
    }
    else if (!messageHome || (messageHome == ""))
    {
        messageHome = "##Infinitive::go## home";
    }
    return messageHome;
}

/////////////////////////////////////////////////////////////////////////////
// This might be more appropriate only existing in the wizard 'class'
public varargs string MessageClone(string msg)
{
    if(msg && stringp(msg))
    {
        messageClone = msg;
    }
    else if (!messageClone || (messageClone == ""))
    {
        messageClone = "##Infinitive::create## something";
    }
    return messageClone;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string Title(string msg)
{
    if (msg && stringp(msg))
    {
        title = msg;
    }
    else if ((!title || (title == "")) && getService("player"))
    {
        title = "the title-less";
    }
    else if(!title)
    {
        title = "";
    }

    return title;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string Pretitle(string msg)
{
    if(msg && stringp(msg))
    {
        pretitle = msg;
    }

    return pretitle;
}

/////////////////////////////////////////////////////////////////////////////
// Overload as needed!
public varargs string short(string newShort)
{
    if(newShort && stringp(newShort))
    {
        shortDescription = newShort;
    }
    else if (!shortDescription || (shortDescription == ""))
    {
        shortDescription = name;
    }
    string ret = shortDescription;
    
    if(Invisibility())
    {
        ret = "";
    }
    if(Ghost())
    {
        ret = sprintf("ghost of %s", shortDescription);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string *Aliases(string *newAliases)
{
    if(newAliases && pointerp(newAliases))
    {
        aliases = newAliases;
    }
    return aliases + ({ name });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addAlias(string newAlias)
{
    int ret = 0;
    if(newAlias && stringp(newAlias) && (member(aliases, newAlias) < 0))
    {
        aliases += ({ newAlias });
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    string *aliasCheck = Aliases() + ({ RealName() });
    
    return (item && stringp(item) && aliasCheck && (member(aliasCheck, item) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed queryProperty(string key)
{
    mixed ret = 0;
    if(key && stringp(key) && member(properties, key))
    {
        ret = properties[key];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setProperty(string key, mixed value)
{
    if(key && stringp(key))
    {
        properties[key] = value;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void clearProperty(string key)
{
    if (key && stringp(key))
    {
        m_delete(properties, key);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int Age()
{
    return age;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string ageString(int time)
{
    if (!time)
    {
        time = age;
    }

    // Eek! Magic numbers everywhere! As soon as I'm getting paid more than
    // $0/hr for this, I'll fix it...
    return sprintf("%s%s%s%s%s", 
        ((time / 31557600) ? sprintf("%d year%s ", (time / 31557600),
            ((time / 31557600) == 1) ? "" : "s") : ""),
        ((time / 86400) ? sprintf("%d day%s ", ((time % 31557600) / 86400),
            (((time % 31557600) / 86400) == 1) ? "" : "s") : ""),
        ((time / 3600) ? sprintf("%d hour%s ", ((time % 86400) / 3600),
            (((time % 86400) / 3600) == 1) ? "" : "s") : ""),
        ((time / 60) ? sprintf("%d minute%s ", ((time % 3600) / 60),
            (((time % 3600) / 60) == 1) ? "" : "s") : ""),
        sprintf("%d second%s", (time % 60), (((time % 60) == 1) ? "" : "s")));
}

/////////////////////////////////////////////////////////////////////////////
public varargs string description(string msg)
{
    if (msg && stringp(msg))
    {
        longDescription = msg;
    }

    return longDescription;
}

/////////////////////////////////////////////////////////////////////////////
private string basicLongDescription()
{
    string ret = capitalize(name);

    if (Pretitle())
    {
        ret = Pretitle() + " " + ret;
    }

    if (Title())
    {
        ret += " " + Title();
    }
    ret += sprintf(" (%s)", GenderDesc());

    object race = getService("races");
    if (race && race->Race())
    {
        ret += sprintf(" (%s)", race->Race());
    }
    ret += "\n";
    if (longDescription && (longDescription != ""))
    {
        ret += longDescription + "\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string inventoryLongDescription(int brief)
{
    string ret = "";
    object inventory = getService("inventory");
    if(inventory)
    {
        ret += inventory->inventoryDescription();

        if(!brief)
        {
            string inventoryText = inventory->inventoryText();

            if(inventoryText && inventoryText != "")
            {
                ret += "\tCarrying:\n" + inventoryText;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(int brief)
{
    string ret = basicLongDescription();

    object wizard = call_other(this_object(), "isRealizationOf", "wizard");
    if(wizard)
    {
        ret += wizard->wizardInformation();
    }

    object combat = getService("combat");
    if(combat)
    {
        ret += sprintf("%s %s\n", capitalize(Pronoun()),
            combat->healthDescription());
    }

    ret += inventoryLongDescription(brief);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int get()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
static nomask varargs void materialAttributesHeartBeat(int ageAmount)
{
    age += ageAmount ? ageAmount : 2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int canSee(int neededLevel)
{
    int ret = 0;
    int lightLevel = 0;
    if (!neededLevel)
    {
        neededLevel = 1;
    }

    object location = environment(this_object());
    if (location)
    {
        lightLevel = location->isIlluminated();
    }

    if (lightLevel < neededLevel)
    {
        object *inventory = all_inventory(this_object());
        if (sizeof(inventory))
        {
            foreach(object item in inventory)
            {
                int itemLight = item->query("light");
                if (itemLight > lightLevel)
                {
                    lightLevel = itemLight;
                }
            }
        }
    }

    object traits = getService("traits");
    if (traits && traits->hasTraitOfRoot("darkvision"))
    {
        lightLevel = neededLevel;
    }

    return (!traits || (traits && (!traits->hasTraitOfRoot("blind")))) ?
        (lightLevel >= neededLevel) : 0;
}
