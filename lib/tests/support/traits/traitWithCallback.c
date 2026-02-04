//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "Prevent Death");
    addSpecification("description", "blah blah blah");
    addSpecification("event handlers", ({ "onAttackEvent",
        "onDamageEvent", "onProtectedFromDeath" }));
    addSpecification("root", "protected from death");
    addSpecification("expire message", "Divine protection fades from you.\n");
    addSpecification("cost", 1);
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
public void onAttackEvent(object owner, object attacker)
{
    // Handler for attack events
}

/////////////////////////////////////////////////////////////////////////////
public void onDamageEvent(object owner, int damage)
{
    // Handler for damage events
}

/////////////////////////////////////////////////////////////////////////////
public void onProtectedFromDeath(object caller)
{
    string colorConfiguration = caller->colorConfiguration() ?
        caller->colorConfiguration() : "none";

    string *traits = caller->TraitsOfRoot("protected from death");
    if(sizeof(traits))
    {
        object trait = getService("traits")->traitObject(traits[0]);
        if(trait)
        {
            tell_object(caller, getService("configuration")->decorate(
                trait->query("expire message"), "death", "combat", 
                colorConfiguration));

            object attacker;
            while (attacker = caller->getTargetToAttack())
            {
                caller->stopFight(attacker);
            }

            move_object(caller, "/areas/eledhel/southern-city/7x2.c");

            tell_object(caller, getService("configuration")->decorate(
                trait->query("expire message"), "death", "combat",
                colorConfiguration));

            caller->unregisterEvent(trait);
            caller->removeTrait(traits[0]);
        }
    }
}
