//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Bonus;
object Player;
object Environment;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");

    Environment = clone_object("/lib/tests/support/environment/bonusRoom.c");
    move_object(Player, Environment);

    Bonus = clone_object("/lib/environment/elementBonus.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Bonus);
    destruct(Player);
    destruct(Environment);
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidBonusThrowsError()
{
    string error = catch (Bonus.setup("blarg", 5));

    ExpectEq("*EnvironmentalElement: The bonus \"blarg\" must be valid as "
        "specified in bonusesDictionary.\n", error);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetUpBonus()
{
    Bonus.setup("strength", 5);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Strength\n"
        "There is a +5 bonus to strength active.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusBySeason()
{
    Bonus.setup("long sword", 5);
    Bonus.limitBonusBySeason("autumn");

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Long Sword\n"
        "There is a +5 bonus to long sword active.\n"
        "This is only applied when the season is autumn.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusByMoonPhase()
{
    Bonus.setup("long sword", 5);
    Bonus.limitBonusByMoonPhase("new moon");
    Bonus.limitBonusByMoonPhase("waxing crescent");
    Bonus.limitBonusByMoonPhase("waning crescent");

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Long Sword\n"
        "There is a +5 bonus to long sword active.\n"
        "This is only applied when the moon phase is one of new moon, "
        "waning crescent,\nor waxing crescent.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusByTimeOfDay()
{
    Bonus.setup("hit points", 3);
    Bonus.limitBonusByTimeOfDay("noon");

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +3 bonus to hit points active.\n"
        "This is only applied when the time of day is noon.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusByState()
{
    Bonus.setup("hit points", -5);
    Bonus.limitBonusByState("exploited");

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a -5 penalty to hit points active.\n"
        "This is only applied when the environment state is exploited.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusBySkills()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusBySkill("forestry", 5);
    Bonus.limitBonusBySkill("agriculture", 3);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when your agriculture skill is at least 3.\n"
        "This is only applied when your forestry skill is at least 5.\n",
        Bonus.getBonusStatistics(Environment, Player));
}


/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByIntoxication()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByIntoxication(5);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you are intoxicated.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByDrugEffect()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByDrugEffect(5);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you are drugged.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByNearnessToDeath()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByNearnessToDeath(10);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you are near death.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayBySpellPointsDrained()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusBySpellPointsDrained(10);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you are spell points drained.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitDisplayByStaminaDrained()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByStaminaDrained(10);

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you are stamina drained.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusByTool()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByEquipment("axe");

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you're using: axe.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanLimitBonusByOneOfTools()
{
    Bonus.setup("hit points", 5);
    Bonus.limitBonusByOneOfEquipment(({ "axe", "sword", "pole-arm" }));

    Bonus.setupBonus(Environment);
    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you're using: axe, pole-arm, or sword.\n",
        Bonus.getBonusStatistics(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyBonusToEnvironmentReturnsCorrectly()
{
    Bonus.setup("hit points", 5);
    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    Bonus.setupBonus(Environment);

    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyBonusToEnvironmentReturnsCorrectlyWhenStateSet()
{
    Bonus.setup("hit points", 5);
    Bonus.setupBonus(Environment);
    Bonus.limitBonusByState("exploited");

    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    Environment.currentState("exploited");
    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyBonusToEnvironmentReturnsCorrectlyWhenMoonPhaseSet()
{
    Bonus.setup("hit points", 5);
    Bonus.setupBonus(Environment);
    Bonus.limitBonusByMoonPhase("waxing crescent");

    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    object dictionary = getDictionary("environment");
    dictionary.setDay(2);

    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));

    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyBonusToEnvironmentReturnsCorrectlyWhenTimeOfDaySet()
{
    Bonus.setup("hit points", 5);
    Bonus.setupBonus(Environment);
    Bonus.limitBonusByTimeOfDay("noon");

    object dictionary = getDictionary("environment");
    dictionary.timeOfDay("morning");

    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    dictionary.timeOfDay("noon");
    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));

    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CanApplyBonusToEnvironmentReturnsCorrectlyWhenSeasonSet()
{
    Bonus.setup("hit points", 5);
    Bonus.setupBonus(Environment);
    Bonus.limitBonusBySeason("autumn");

    object dictionary = getDictionary("environment");
    dictionary.setDay(20);

    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    dictionary.setDay(260);
    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));

    destruct(dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysAndResolvesMultipleLimitors()
{
    set_this_player(Player);
    Bonus.setup("hit points", 5);
    Bonus.setupBonus(Environment);
    Bonus.limitBonusBySeason("autumn");
    Bonus.limitBonusByOneOfEquipment(({ "axe", "sword", "pole-arm" }));
    Bonus.limitBonusBySkill("forestry", 5);

    ExpectEq("Name: Hit Points\n"
        "There is a +5 bonus to hit points active.\n"
        "This is only applied when you're using: axe, pole-arm, or sword.\n"
        "This is only applied when the season is autumn.\n"
        "This is only applied when your forestry skill is at least 5.\n", 
        Bonus.getBonusStatistics(Environment, Player));

    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    object dictionary = getDictionary("environment");
    dictionary.setDay(260);
    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    Player.addSkillPoints(20);
    Player.advanceSkill("forestry", 5);
    ExpectFalse(Bonus.canApplyBonusToEnvironment(Environment, Player));

    object axe = clone_object("/lib/instances/items/weapons/axes/axe.c");
    move_object(axe, Player);
    command("equip axe", Player);

    ExpectTrue(Bonus.canApplyBonusToEnvironment(Environment, Player));

    destruct(dictionary);
}
