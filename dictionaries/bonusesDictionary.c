//*****************************************************************************
// Class: bonusesDictionary
// File Name: bonusesDictionary.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
private nosave string LibDirectory = "lib/dictionaries";

private string *bonuses = 0;

/////////////////////////////////////////////////////////////////////////////
private nomask object getDictionary(string service)
{
    object ret = 0;
    
    if(service && stringp(service))
    {
        string dictionary = sprintf("/%s/%sDictionary.c", LibDirectory,
            service);
        if(file_size(dictionary) > -1)
        {
            ret = load_object(dictionary);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *bonusList()
{
    if(!bonuses)
    {
        bonuses = ({ "strength", "intelligence", "dexterity", "wisdom",
        "constitution", "charisma", "to intoxicated", "to stuffed",
        "to drugged", "to soaked", "headache", "armor class", "defense class",
        "attack", "soak", "hit points", "spell points", "stamina points",
        "heal hit points rate", "heal hit points", "heal spell points",
        "heal spell points rate", "heal stamina", "heal stamina rate", 
        "reduce spell points", "recover spell points", "reduce stamina points", 
        "recover stamina points", "weapon attack", "defense", "damage" });
    
        object attacksDictionary = getDictionary("attacks");
        if(attacksDictionary && function_exists("validAttackTypes", 
           attacksDictionary))
        {
            string *attackList = attacksDictionary->validAttackTypes();
            foreach(string attack : attackList)
            {
                if(attack && stringp(attack))
                {
                    bonuses += ({ sprintf("%s attack", attack) });
                }
            }
        }
        
        object skillsDictionary = getDictionary("skills");
        if(skillsDictionary && function_exists("validSkills", skillsDictionary))
        {
            bonuses += skillsDictionary->validSkills();
        }
    }
    return bonuses + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonus(string bonus)
{
    return (bonus && stringp(bonus) &&
        (member(bonusList(), bonus) > -1));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidBonusModifier(string bonus, int amount)
{
    return (isValidBonus(bonus)); // &&*
    //TODO: Finish me
}

