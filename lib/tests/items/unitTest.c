//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Room;
object AttackingOwner;
object AttackingUnit;
object DefendingOwner;
object DefendingUnit;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    AttackingOwner = clone_object("/lib/tests/support/services/mockPlayer.c");
    AttackingOwner->Name("fred");
    AttackingOwner->Gender("male");
    AttackingOwner->colorConfiguration("none");
    AttackingUnit = clone_object("/lib/tests/support/tactical-combat/testKnight.c");
    AttackingUnit->set("unit leader", "fred");

    DefendingOwner = clone_object("/lib/tests/support/services/mockPlayer.c");
    DefendingOwner->Name("henrietta");
    DefendingOwner->Gender("female");
    DefendingOwner->colorConfiguration("none");
    DefendingUnit = clone_object("/lib/tests/support/tactical-combat/testArcher.c");
    DefendingUnit->set("unit leader", "henrietta");

    Room = clone_object("/lib/environment/environment.c");
    move_object(AttackingOwner, Room);
    move_object(AttackingUnit, Room);
    move_object(DefendingOwner, Room);
    move_object(DefendingUnit, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(AttackingOwner);
    destruct(AttackingUnit);
    destruct(DefendingOwner);
    destruct(DefendingUnit);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void SettingFewerThanZeroTroopCountSetsValueToZero()
{
    ExpectEq(10, AttackingUnit->query("troop count"));

    AttackingUnit->set("troop count", -2);
    ExpectEq(0, AttackingUnit->query("troop count"));
}

/////////////////////////////////////////////////////////////////////////////
void SettingTroopCountSetsValueCorrectly()
{
    ExpectEq(10, AttackingUnit->query("troop count"));

    AttackingUnit->set("troop count", 0);
    ExpectEq(0, AttackingUnit->query("troop count"));

    AttackingUnit->set("troop count", 7);
    ExpectEq(7, AttackingUnit->query("troop count"));
}

/////////////////////////////////////////////////////////////////////////////
void SettingTroopCountHigherThanTenThrows()
{
    ExpectEq(10, AttackingUnit->query("troop count"));

    string error = catch(AttackingUnit->set("troop count", 20));
    ExpectEq("*unit.c: Troop count must be between 1 and 10.\n", error);
}

/////////////////////////////////////////////////////////////////////////////
void CanAttackUnit()
{
    ExpectEq("10", AttackingUnit->query("troop count"));
    ExpectEq("10", DefendingUnit->query("troop count"));
    AttackingUnit->attackUnit("archers");
    ExpectEq("6", AttackingUnit->query("troop count"));
    ExpectEq("5", DefendingUnit->query("troop count"));

    ExpectEq("Your knights charge headlong into the fray, disrupting the line of archers.\n"
        "Henrietta's archers tear into the line of your knights.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    6 of your knights still remain alive.\n"
        "    5 of Henrietta's archers still remain alive.\n", 
        AttackingOwner->caughtMessage());
    ExpectEq("Your archers tear into the line of Fred's knights.\n"
        "Fred's knights charge headlong into the fray, disrupting the line of archers.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    6 of Fred's knights still remain alive.\n"
        "    5 of your archers still remain alive.\n", 
        DefendingOwner->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DestroyedUnitsDisplayDestroyedMessage()
{
    DefendingUnit->set("troop count", 2);
    AttackingUnit->attackUnit("archers");
    ExpectFalse(DefendingUnit);

    ExpectEq("Your knights charge headlong into the fray, disrupting the line of archers.\n"
        "Henrietta's archers fail to do any significant damage to your knights.\n"
        "The archers have been destroyed.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "   10 of your knights still remain alive.\n"
        "    0 of Henrietta's archers still remain alive.\n",
        AttackingOwner->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LowMoraleTroopsWillFleeWhenHeavilyDamaged()
{
    DefendingUnit->set("unit morale", 0);
    DefendingUnit->set("troop count", 9);
    AttackingUnit->attackUnit("archers");

    ExpectEq("Your knights charge headlong into the fray, disrupting the line of archers.\n"
        "Henrietta's archers succeed in a minor feint which causes light casualties to\n"
        "your knights.\n"
        "The group of archers was routed.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    9 of your knights still remain alive.\n"
        "    4 of Henrietta's archers still remain alive.\n",
        AttackingOwner->caughtMessage());

    ExpectEq("Your archers succeed in a minor feint which causes light casualties to Fred's\n"
        "knights.\n"
        "The group of archers was routed.\n"
        "Fred's knights charge headlong into the fray, disrupting the line of archers.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    9 of Fred's knights still remain alive.\n"
        "    4 of your archers still remain alive.\n",
        DefendingOwner->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorsDisplayedCorrectly()
{
    AttackingOwner->colorConfiguration("3-bit");
    AttackingUnit->attackUnit("archers");

    ExpectEq("\x1b[0;36mYour knights charge headlong into the fray, disrupting the line of archers.\n\x1b[0m"
        "\x1b[0;31;1m\x1b[0m\x1b[0;35mHenrietta's archers tear into the line of your knights.\n\x1b[0m"
        "\x1b[0;31;1m\x1b[0m\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m"
        "\x1b[0;36m    6 of your knights still remain alive.\n"
        "    5 of Henrietta's archers still remain alive.\n\x1b[0m",
        AttackingOwner->caughtMessage());
    ExpectEq("Your archers tear into the line of Fred's knights.\n"
        "Fred's knights charge headlong into the fray, disrupting the line of archers.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    6 of Fred's knights still remain alive.\n"
        "    5 of your archers still remain alive.\n",
        DefendingOwner->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorsDisplayedCorrectly()
{
    AttackingOwner->colorConfiguration("8-bit");
    AttackingUnit->attackUnit("archers");

    ExpectEq("\x1b[0;38;5;25mYour knights charge headlong into the fray, disrupting the line of archers.\n\x1b[0m"
        "\x1b[0;38;5;9;1m\x1b[0m\x1b[0;38;5;180mHenrietta's archers tear into the line of your knights.\n\x1b[0m"
        "\x1b[0;38;5;9;1m\x1b[0m\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m"
        "\x1b[0;38;5;80m    6 of your knights still remain alive.\n"
        "    5 of Henrietta's archers still remain alive.\n\x1b[0m",
        AttackingOwner->caughtMessage());
    ExpectEq("Your archers tear into the line of Fred's knights.\n"
        "Fred's knights charge headlong into the fray, disrupting the line of archers.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    6 of Fred's knights still remain alive.\n"
        "    5 of your archers still remain alive.\n",
        DefendingOwner->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorsDisplayedCorrectly()
{
    AttackingOwner->colorConfiguration("24-bit");
    AttackingUnit->attackUnit("archers");

    ExpectEq("\x1b[0;38;2;140;140;170mYour knights charge headlong into the fray, disrupting the line of archers.\n\x1b[0m"
        "\x1b[0;38;2;200;0;0;1m\x1b[0m\x1b[0;38;2;140;170;140mHenrietta's archers tear into the line of your knights.\n\x1b[0m"
        "\x1b[0;38;2;200;0;0;1m\x1b[0m\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m"
        "\x1b[0;38;2;180;180;190m    6 of your knights still remain alive.\n"
        "    5 of Henrietta's archers still remain alive.\n\x1b[0m",
        AttackingOwner->caughtMessage());
    ExpectEq("Your archers tear into the line of Fred's knights.\n"
        "Fred's knights charge headlong into the fray, disrupting the line of archers.\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Results +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "    6 of Fred's knights still remain alive.\n"
        "    5 of your archers still remain alive.\n",
        DefendingOwner->caughtMessage());
}
