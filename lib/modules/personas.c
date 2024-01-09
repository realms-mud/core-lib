//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private nosave int researchFrequency = 35;
private nosave string Persona = 0;
private nosave string overrideAssessment = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask string persona()
{
    return Persona;
}

/////////////////////////////////////////////////////////////////////////////
private void setMonsterLevel(int level)
{
    call_direct(this_object(), "effectiveLevel", level);
}

/////////////////////////////////////////////////////////////////////////////
private void setHenchmanLevel(int level)
{
    // Need to implement in task 226
    call_direct(this_object(), "effectiveLevel", level);
}

/////////////////////////////////////////////////////////////////////////////
private void setPersonaLevel(int level)
{
    if (getService("monster"))
    {
        setMonsterLevel(level);
    }
    else if (getService("henchman"))
    {
        setHenchmanLevel(level);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void SetUpPersonaOfLevel(string persona, int level,
    int setMinimumLevelAutomatically)
{
    object livingObj = getService("living");
    if (livingObj)
    {
        object personaDictionary = getDictionary("persona");
        
        int levelToSet = setMinimumLevelAutomatically ?
            personaDictionary->getValidLevel(persona, level, this_object()) :
            level;

        setPersonaLevel(levelToSet);

        personaDictionary->setupPersona(persona, this_object());
        Persona = persona;
    }
    else
    {
        raise_error("Personas: Cannot set up a persona on a non-living object.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setUpRandomEquipment(int chanceForMagicalItems)
{
    object livingObj = getService("living");
    if (livingObj)
    {
        object *equipment = getDictionary("persona")->getRandomEquipment(this_object(),
            chanceForMagicalItems);

        foreach(object item in equipment)
        {
            move_object(item, livingObj);
            livingObj->equip(item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void executePersonaResearch(string target, string specificResearch)
{
    object research = getService("research");
    if (objectp(research) && (random(100) < researchFrequency))
    {
        string *potentialResearchItems = filter(research->completedResearch(),
            (: getDictionary("research")->isActiveOrSustainedAbility($1) :));

        if (sizeof(potentialResearchItems))
        {
            string researchItemString = specificResearch ? specificResearch :
                potentialResearchItems[random(sizeof(potentialResearchItems))];

            object researchItem =
                getDictionary("research")->researchObject(researchItemString);

            if (researchItem)
            {
                string *commandList = researchItem->commandList();
                if (sizeof(commandList))
                {
                    string commandString = commandList[0];
                    if (researchItem->query("effect") == "beneficial")
                    {
                        commandString = regreplace(commandString,
                            "at ##Target##", sprintf("at %s",
                                this_object()->RealName() || ""), 1);
                    }
                    else
                    {
                        commandString = regreplace(commandString,
                            "##Target##", target, 1);
                    }
                    research->researchCommand(commandString);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setResearchFrequency(int newFrequency)
{
    if (intp(newFrequency) && (newFrequency >= 0) && (newFrequency <= 100))
    {
        researchFrequency = newFrequency;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPersonality(string personality)
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask float calculateStrengthOfAttack(object attacker, object defender)
{
    float ret = 0;

    foreach(mapping attack in attacker->getAttacks())
    {
        object weapon;
        if (getDictionary("attacks")->isWeaponAttack(attack))
        {
            weapon = attacker->equipmentInSlot(attack["attack type"]);
            if (!weapon)
            {
                weapon = getDictionary("attacks")->getAttack("unarmed");
            }
        }
        else if (getDictionary("attacks")->isValidAttack(attack))
        {
            weapon = 
                getDictionary("attacks")->getAttack(attack["attack type"]);

            weapon->setAttackValues(attack["damage"], attack["to hit"]);
        }

        string damageType = weapon->getDamageType() ? 
            weapon->getDamageType() : "physical";

        int potentialDamage = attacker->calculateDamage(weapon, damageType, 1) -
            defender->calculateSoakDamage(damageType);

        if (potentialDamage < 1)
        {
            potentialDamage = 1;
        }

        float attackAdjustment =
            (100.0 + attacker->calculateAttack(defender, weapon, 1)) / 100.0;

        ret += attackAdjustment * potentialDamage;
    }

    return ret + attacker->effectiveLevel();
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getCombatComparison(object persona, object player)
{
    string ret = "";

    if (!persona)
    {
        persona = this_object();
    }
    if (!player)
    {
        player = this_player();
    }

    if (player->displayLevelComparison())
    {
        float personaPoints = calculateStrengthOfAttack(persona, player);
        float playerPoints = calculateStrengthOfAttack(player, persona);
        float comparison = (personaPoints - playerPoints) / 
            (playerPoints + personaPoints);

        object configuration = getDictionary("configuration");

        if (persona->overrideCombatAssessment())
        {
            ret = configuration->decorate(persona->overrideCombatAssessment(),
                "override", "combat assessment", player->colorConfiguration());
        }
        else if (comparison < -0.8)
        {
            ret = configuration->decorate(" [Very Easy]",
                "very easy", "combat assessment", player->colorConfiguration());
        }
        else if (comparison < -0.50)
        {
            ret = configuration->decorate(" [Easy]",
                "easy", "combat assessment", player->colorConfiguration());
        }
        else if (comparison < -0.20)
        {
            ret = configuration->decorate(" [Somewhat Easy]",
                "somewhat easy", "combat assessment", 
                player->colorConfiguration());
        }
        else if (comparison < 0.20)
        {
            ret = configuration->decorate(" [Even]",
                "even", "combat assessment", player->colorConfiguration());
        }
        else if (comparison < 0.50)
        {
            ret = configuration->decorate(" [Somewhat Challenging]",
                "somewhat challenging", "combat assessment", 
                player->colorConfiguration());
        }
        else if (comparison < 0.80)
        {
            ret = configuration->decorate(" [Challenging]",
                "challenging", "combat assessment",
                player->colorConfiguration());
        }
        else
        {
            ret = configuration->decorate(" [Suicidal]",
                "suicidal", "combat assessment", player->colorConfiguration());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string overrideCombatAssessment()
{
    return overrideAssessment;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void customCombatAssessment(string assessment)
{
    overrideAssessment = assessment;
    if (overrideAssessment)
    {
        overrideAssessment = regreplace(overrideAssessment,
            "(\\[|\\])", "", 1);

        string *words = explode(overrideAssessment, " ");
        int size = sizeof(words);
        for (int i = 0; i < size; i++)
        {
            words[i] = capitalize(words[i]);
        }

        overrideAssessment = sprintf(" [%s]", implode(words, " "));
    }
}
