//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Element;
object Player;
object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = getService("environment");
    Service.setYear(1);
    Service.setDay(92);
    Service.timeOfDay("noon");

    Element = clone_object("/lib/tests/support/environment/testElement.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Element);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayBySeason()
{
    string season = "autumn";
    Element.testLimitDisplayBySeason(season);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Service.setDay(260);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
 }

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByTimeOfDay()
{
    string timeOfDay = "evening";
    Element.testLimitDisplayByTimeOfDay(timeOfDay);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Service.timeOfDay("evening");
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByMoonPhase()
{
    string moonPhase = "waning gibbous";
    Element.testLimitDisplayByMoonPhase(moonPhase);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Service.setDay(18);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByState()
{
    object room = 
        load_object("/lib/tests/support/environment/bonusRoom.c");

    move_object(Player, "/lib/tests/support/environment/bonusRoom.c");

    Element.testLimitDisplayByState("blarg");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    room.currentState("blarg");
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByEquipment()
{
    Element.testLimitDisplayByEquipment("axe");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    
    object axe = clone_object("/lib/instances/items/weapons/axes/axe.c");
    move_object(axe, Player);
    command("wield axe", Player);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByOneOfEquipment()
{
    Element.testLimitDisplayByOneOfEquipment(({ "axe", "long sword" }));

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    
    object sword = 
        clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    move_object(sword, Player);
    command("wield sword", Player);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayBySkill()
{
    Element.testLimitDisplayBySkill("listen", 6);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.addSkillPoints(20);
    Player.advanceSkill("listen", 6);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByAttribute()
{
    Element.testLimitDisplayByAttribute("strength", 5);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.Str(10);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByQuest()
{
    Element.testLimitDisplayByQuest(
        "/lib/tests/support/quests/fakeQuestItem.c");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");

    Player.beginQuest("/lib/tests/support/quests/fakeQuestItem.c");
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");

    Player.advanceQuestState("/lib/tests/support/quests/fakeQuestItem.c",
        "met the king");
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");

    Player.advanceQuestState("/lib/tests/support/quests/fakeQuestItem.c",
        "serve the king");
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");

    Player.advanceQuestState("/lib/tests/support/quests/fakeQuestItem.c",
        "save the king");
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByResearch()
{
    Element.testLimitDisplayByResearch(
        "/lib/tests/support/research/testResearchA.c");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.addResearchPoints(1);
    Player.initiateResearch("/lib/tests/support/research/testResearchA.c");
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByTrait()
{
    Element.testLimitDisplayByTrait(
        "/lib/tests/support/traits/testGeneticTrait.c");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.addTrait("/lib/tests/support/traits/testGeneticTrait.c");
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByResearchThatIsActive()
{
    move_object(Player, "/lib/tests/support/environment/bonusRoom.c");
    Element.testLimitDisplayByResearchThatIsActive(
        "/lib/tests/support/research/testSustainedTraitResearch.c");
    Player.spellPoints(Player.maxSpellPoints());

    Player.initiateResearch("/lib/tests/support/research/testSustainedTraitResearch.c");

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    ExpectTrue(Player.researchCommand("throw turnip"));
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByIntoxication()
{
    Element.testLimitDisplayByIntoxication(5);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.addIntoxication(5);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByDrugEffect()
{
    Element.testLimitDisplayByDrugEffect(5);

    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
    Player.Drugged(10);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByNearnessToDeath()
{
    Element.testLimitDisplayByNearnessToDeath(10);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
    Player.hitPoints(Player.maxHitPoints());
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayBySpellPointsDrained()
{
    Element.testLimitDisplayBySpellPointsDrained(10);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
    Player.spellPoints(Player.maxSpellPoints());
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByStaminaDrained()
{
    Element.testLimitDisplayByStaminaDrained(10);
    ExpectTrue(Element.elementIsAvailable(Player), "value is set");
    Player.staminaPoints(Player.maxStaminaPoints());
    ExpectFalse(Element.elementIsAvailable(Player), "value is not set");
}
