//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string *hitDictionary = 0;
private string *simileDictionary = 0;
private mapping damageMessages = ([ ]);

private nosave string AttacksDictionary = "/lib/dictionaries/attacksDictionary.c";
private string damageType = "generic";
private int canDamageEthereal = 0;

private int toHit;
private int damage;
private int initialized = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask int isInitialized()
{
    return initialized;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int setDamageType(string dmgType)
{
    int ret = 0;
    object attackDictionary = load_object(AttacksDictionary);
    if(attackDictionary && attackDictionary->isValidDamageType(dmgType))
    {
        damageType = dmgType;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getDamageType()
{
    return damageType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canDamageEthereal()
{
    return canDamageEthereal;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void damagesEthereal()
{
    canDamageEthereal = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int attackTypeCalculateAttack()
{
    int ret = 0;
    if(toHit)
    {
        ret = toHit;
    }
    else
    {
        ret = 25 + random(26);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int attackTypeCalculateDamage()
{
    return damage;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setAttackValues(int newDamage, int newHit)
{
    // Technically, this isn't safe as there's only one object of this type per
    // attack and there's a slight chance that if two executions happen 
    // simultaneously, the wrong hit/damage will be applied. It's only a game,
    // however, and not worth cloning a copy for what is quite probably a very
    // unlikely occurance - these will get used immediately after invocation.
    damage = newDamage;
    toHit = newHit;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getMessage(int damageInflicted)
{
    string *messages = ({ });
    
    if(damageInflicted < 1)
    {
        if(member(damageMessages, "miss"))
        {
            messages = damageMessages["miss"];
        }
        else
        {
            messages = ({ "##AttackerName## ##Infinitive::miss##" });
        }
    }
    else
    {
        foreach(string range : m_indices(damageMessages))
        {
            int high = 0x7fffffff;
            int low = 0;
            
            if(range && stringp(range) && ((range == "default") ||
               sscanf(range, "%d-%d", low, high) ||
               sscanf(range, "> %d", low) || sscanf(range, "< %d", high)))
            {
                if((damageInflicted >= low) && (damageInflicted <= high))
                {
                    messages += damageMessages[range];
                }
            }
        }
        
        if(!sizeof(messages))
        {
            messages += ({ "##AttackerName## ##Infinitive::hit## ##TargetName##" });
        }
    }
    return messages[random(sizeof(messages))];            
}
                
/////////////////////////////////////////////////////////////////////////////
protected nomask int addHitDictionary(string *dictionary)
{
    hitDictionary = dictionary + ({ });
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSimileDictionary(string *dictionary)
{
    simileDictionary = dictionary + ({ });
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs int addHitMessage(string message, string damage)
{
    int ret = 0;
    string key = damage ? damage : "default";
    
    int high;
    int low;
    
    if((key == "default") || sscanf(key, "%d-%d", low, high) ||
       sscanf(key, "> %d", low) || sscanf(key, "< %d", high) ||
       (key == "miss"))
    {
        if(message && stringp(message))
        {
            if(!member(damageMessages, key))
            {
                damageMessages[key] = ({ message });
            }
            else
            {
                damageMessages[key] += ({ message });
            }
            ret = 1;
        }
    }
    else
    {
        raise_error(sprintf("baseAttack: The damage type '%s' is invalid.\n",
            damage));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addMissMessage(string message)
{
    return addHitMessage(message, "miss");
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getRandomSimile()
{
    string ret = "";
    if(simileDictionary && sizeof(simileDictionary))
    {
        ret = simileDictionary[random(sizeof(simileDictionary))];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getRandomVerb()
{
    string ret = "";
    if(hitDictionary && sizeof(hitDictionary))
    {
        ret = sprintf("##Infinitive::%s##",
            hitDictionary[random(sizeof(hitDictionary))]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        initialized = 1;
    }
}


