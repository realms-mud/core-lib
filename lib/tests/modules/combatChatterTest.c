//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Attacker;
object Target;
object Dictionary;
object Room;

/////////////////////////////////////////////////////////////////////////////
void SetUpMessages()
{
    if (objectp(Target))
    {
        Target.addDefensiveMissCombatMessage("##InitiatorName## ##Infinitive::snarl## at ##TargetName##, `You're bad at this!'");
        Target.addOffensiveMissCombatMessage("##InitiatorName## ##Infinitive::whine##, `Stand still!'");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::laugh##, `I am immense and immortal.'", "is in good shape.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::taunt##, `Come on, you pansy!'", "is barely inured.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::taunt##, `Ouch, you mean dickweed.'", "has some minor injuries.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::shrug##, `'Tis but a scratch'", "has been roughed up.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::snort##, `'Tis only a flesh wound'", "has taken a beating.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::growl##, `Yer starting to piss me off now.'", "is severely injured.");
        Target.addDefensiveHitCombatMessage("##InitiatorName## ##Infinitive::scream##, `Come here and take what's coming to ya!'", "is knocking on death's door.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::laugh##, `Take that, dipshit!'", "is in good shape.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::taunt##, `What's that you got on your face?'", "is barely inured.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::taunt##, `Quit hitting yourself!'", "has some minor injuries.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::shrug##, `You suck at this.'", "has been roughed up.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::snort##, `Quit bleeding on my weapon, you dolt!'", "has taken a beating.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::growl##, `Now yer gonna die wearing that stupid outfit. How does it feel?'", "is severely injured.");
        Target.addOffensiveHitCombatMessage("##InitiatorName## ##Infinitive::sigh##, `Poor soon-to-be dead bastard...'", "is knocking on death's door.");
    }
}

/////////////////////////////////////////////////////////////////////////////
void SetUpAttacker()
{
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker.Name("Bob");
    Attacker.Race("human");
    Attacker.Str(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Chr(20);
    Attacker.hitPoints(Attacker.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTarget()
{
    Target = clone_object("/lib/realizations/monster.c");
    Target.Name("Nukulevee");
    Target.Race("undead horse");
    Target.SetUpPersonaOfLevel("nukulevee", 20);
    Target.setUpRandomEquipment(100);
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpAttacker", "SetUpTarget", "SetUpMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SetUpAttacker();
    SetUpTarget();
    Room = clone_object("/lib/tests/support/environment/fakeCombatRoom");
    move_object(Attacker, Room);
    move_object(Target, Room);

    Dictionary = load_object("/lib/dictionaries/combatChatterDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Room);
    destruct(Target);
    destruct(Attacker);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CombatChatterNotAvailableOnPlayers()
{
    ExpectEq(-1, member(inherit_list(Attacker), "/lib/modules/combatChatter.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatChatterAvailableOnMonsters()
{
    ExpectNotEq(-1, member(inherit_list(Target), "/lib/modules/combatChatter.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDeathMessage()
{
    Target.addDeathMessage("##InitiatorName## ##Infinitive::look## at ##TargetName## "
        "and ##Infinitive::gasp##, `I just wanted a jar of dried beef.'");
    Target.hit(20000, "fire", Attacker);
    ExpectSubStringMatch("Nukulevee looks at you and gasps, `I just wanted a jar of dried beef",
        Attacker.caughtMessages()[2]);
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeKillMessage()
{
    object shadow = clone_object("/lib/tests/support/services/catchShadow.c");
    shadow.beginShadow(Target);

    Target.addKillMessage("##InitiatorName## ##Infinitive::look## at ##TargetName## "
        "and ##Infinitive::laugh##, `Hah! Hah!'");
    Attacker.hit(20000, "fire", Target);
    ExpectSubStringMatch("You look at Bob and laugh, `Hah! Hah!'",
        Target.caughtMessages());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveMissMessage()
{
    SetUpMessages();
    Dictionary.displayCombatChatter(0, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee snarls at you, `You're bad at this!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveNotReallyWoundedMessage()
{
    SetUpMessages();
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee laughs, `I am immense and immortal.'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveBarelyWoundedMessage()
{
    SetUpMessages();
    Target.hit(3 * Target.maxHitPoints() / 16, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee taunts, `Come on, you pansy!",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveLightlyWoundedMessage()
{
    SetUpMessages();
    Target.hit(3 * Target.maxHitPoints() / 8, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee taunts, `Ouch, you mean dickweed.'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveWoundedMessage()
{
    SetUpMessages();
    Target.hit(5 * Target.maxHitPoints() / 8, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee shrugs, `'Tis but a scratch'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveBeatenUpMessage()
{
    SetUpMessages();
    Target.hit(13 * Target.maxHitPoints() / 16, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee snorts, `'Tis only a flesh wound'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveSeverelyWoundedMessage()
{
    SetUpMessages();
    Target.hit((15 * Target.maxHitPoints() / 16) - 1, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee growls, `Yer starting to piss me off now.'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeDefensiveNearDeathMessage()
{
    SetUpMessages();
    Target.hit(31 * Target.maxHitPoints() / 32, "fire");
    Dictionary.displayCombatChatter(1, Attacker, Target, 1);
    ExpectSubStringMatch("Nukulevee screams, `Come here and take what's coming to ya!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveMissMessage()
{
    SetUpMessages();
    Dictionary.displayCombatChatter(0, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee whines, `Stand still!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveNotReallyWoundedMessage()
{
    SetUpMessages();
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee laughs, `Take that, dipshit!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveBarelyWoundedMessage()
{
    SetUpMessages();
    Attacker.hit(3 * Attacker.maxHitPoints() / 16, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee taunts, `What's that you got on your face?'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveLightlyWoundedMessage()
{
    SetUpMessages();
    Attacker.hit(3 * Attacker.maxHitPoints() / 8, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee taunts, `Quit hitting yourself!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveWoundedMessage()
{
    SetUpMessages();
    Attacker.hit(5 * Attacker.maxHitPoints() / 8, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee shrugs, `You suck at this.'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveBeatenUpMessage()
{
    SetUpMessages();
    Attacker.hit(13 * Attacker.maxHitPoints() / 16, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee snorts, `Quit bleeding on my weapon, you dolt!'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveSeverelyWoundedMessage()
{
    SetUpMessages();
    Attacker.hit(15 * Attacker.maxHitPoints() / 16, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee growls, `Now yer gonna die wearing that stupid outfit. How does it\nfeel?'",
        Attacker.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSeeOffensiveNearDeathMessage()
{
    SetUpMessages();
    Attacker.hit(Attacker.maxHitPoints() - 1, "fire");
    Dictionary.displayCombatChatter(1, Target, Attacker, 1);
    ExpectSubStringMatch("Nukulevee sighs, `Poor soon-to-be dead bastard...'",
        Attacker.caughtMessage());
}
