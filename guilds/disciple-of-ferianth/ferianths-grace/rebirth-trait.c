//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Rebirth");
    addSpecification("type", "effect");
    addSpecification("root", "protected from death");
    addSpecification("duration", 1800);
    addSpecification("expire message", "The protective flames of Ferianth "
        "fade from around you.\n");
    addSpecification("description", "Divine flames surround you, ready to "
        "restore you to life should you fall.");
    addSpecification("event handlers", ({ "onProtectedFromDeath" }));
}

/////////////////////////////////////////////////////////////////////////////
public void onProtectedFromDeath(object caller)
{
    if (!caller || !objectp(caller))
    {
        return;
    }

    string colorConfiguration = caller->colorConfiguration() ?
        caller->colorConfiguration() : "none";

    string *traits = caller->TraitsOfRoot("protected from death");
    if (sizeof(traits) && 
        (member(traits, program_name(this_object())) > -1))
    {
        object configuration = getService("configuration");

        // Display the rebirth message
        tell_object(caller, configuration->decorate(
            "\nAs death reaches for you, Ferianth's divine fire erupts! "
            "Your body is consumed in holy flames and rises anew from "
            "the ashes!\n\n",
            "resurrection", "combat", colorConfiguration));

        // Stop all combat
        object attacker;
        while (attacker = caller->getTargetToAttack())
        {
            caller->stopFight(attacker);
        }

        // Restore hit points to 50%
        int maxHP = caller->maxHitPoints();
        caller->hitPoints(maxHP / 2);

        // Restore some spell and stamina points
        int maxSP = caller->maxSpellPoints();
        int maxST = caller->maxStaminaPoints();
        caller->spellPoints(maxSP / 4);
        caller->staminaPoints(maxST / 4);

        tell_object(caller, configuration->decorate(
            sprintf("You have been restored to %d hit points.\n",
                caller->hitPoints()),
            "resurrection", "combat", colorConfiguration));

        // Unregister and remove the trait (one-time use)
        caller->unregisterEvent(this_object());
        caller->removeTrait(program_name(this_object()));
    }
}
