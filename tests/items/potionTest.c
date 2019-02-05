//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("Bob");
    Player->Str(20);
    Player->Int(20);
    Player->Dex(20);
    Player->Con(20);
    Player->Wis(20);
    Player->Chr(20);
    move_object(Player, this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanQuaffPotionAndHaveHitPointIncreaseApplied()
{
    object potion = clone_object("/lib/instances/items/potions/healing.c");
    move_object(potion, Player);

    ExpectEq(0, Player->hitPoints());
    ExpectTrue(present("potion", Player));
    command("quaff potion", Player);
    ExpectEq(100, Player->hitPoints());
    ExpectSubStringMatch("You quaff Healing Potion.", Player->caughtMessage());
    ExpectFalse(present("potion", Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanDrinkPotionAndHaveSpellPointIncreaseApplied()
{
    object potion = clone_object("/lib/instances/items/potions/mana.c");
    move_object(potion, Player);

    ExpectEq(0, Player->spellPoints());
    ExpectTrue(present("potion", Player));
    command("drink potion", Player);
    ExpectEq(100, Player->spellPoints());
    ExpectSubStringMatch("You drink Mana Potion.", Player->caughtMessage());
    ExpectFalse(present("potion", Player));
}

/////////////////////////////////////////////////////////////////////////////
void CanConsumePotionAndHaveStaminaPointIncreaseApplied()
{
    object potion = clone_object("/lib/instances/items/potions/stamina.c");
    move_object(potion, Player);

    ExpectEq(0, Player->staminaPoints());
    ExpectTrue(present("potion", Player));
    command("consume potion", Player);
    ExpectEq(100, Player->staminaPoints());
    ExpectSubStringMatch("You consume Stamina Potion.", Player->caughtMessage());
    ExpectFalse(present("potion", Player));
}

/////////////////////////////////////////////////////////////////////////////
void DrinkingPotionWithBiologicalEffectHasEffectApplied()
{
    object potion = clone_object("/lib/instances/items/potions/stamina.c");
    move_object(potion, Player);

    ExpectFalse(Player->isTraitOf("lib/modules/traits/biological/adrenaline.c"));

    command("drink potion", Player);
    ExpectTrue(Player->isTraitOf("lib/modules/traits/biological/adrenaline.c"));
}

/////////////////////////////////////////////////////////////////////////////
void DrinkingPotionWithTraitEffectHasTraitApplied()
{
    object potion = 
        clone_object("/lib/instances/items/potions/tears-of-ilyrth.c");
    move_object(potion, Player);

    ExpectFalse(Player->isTraitOf("lib/instances/items/potions/traits/tears-of-ilyrth.c"));
    ExpectEq(0, Player->hitPoints());
    ExpectEq(150, Player->maxHitPoints());
    ExpectEq(0, Player->spellPoints());
    ExpectEq(150, Player->maxSpellPoints());

    command("drink potion", Player);

    ExpectTrue(Player->isTraitOf("lib/instances/items/potions/traits/tears-of-ilyrth.c"));
    ExpectEq(100, Player->hitPoints());
    ExpectEq(250, Player->maxHitPoints());
    ExpectEq(100, Player->spellPoints());
    ExpectEq(250, Player->maxSpellPoints());
}
