//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Character;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");

    ToggleCallOutBypass();
    Character = clone_object("/lib/tests/support/services/mockPlayer");
    Character.Name("Bob");
    Character.Con(5);

    setUsers(({ Character }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Character);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedSetsIntoxicationLevel()
{
    ExpectEq(0, Character.Intoxicated());
    ExpectEq(10, Character.Intoxicated(10));
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedFiresOnIntoxicationChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character.Intoxicated());

    string err = catch (Character.Intoxicated(10); nolog);
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationWithoutValueReturnsFalse()
{
    ExpectFalse(Character.addIntoxication());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanAddToIntoxValue()
{
    ExpectEq(0, Character.Intoxicated());
    ExpectTrue(Character.addIntoxication(10));
    ExpectEq(10, Character.Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanRemoveFromIntoxValue()
{
    ExpectEq(10, Character.Intoxicated(10));
    ExpectTrue(Character.addIntoxication(-5));
    ExpectEq(5, Character.Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character.Intoxicated(10));
    ExpectTrue(Character.addIntoxication(-15));
    ExpectEq(0, Character.Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.addIntoxication(10); nolog);
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void StuffedSetsStuffedLevel()
{
    ExpectEq(0, Character.Stuffed());
    ExpectEq(10, Character.Stuffed(10));
}

/////////////////////////////////////////////////////////////////////////////
void StuffedFiresOnStuffedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onStuffedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character.Stuffed());

    string err = catch (Character.Stuffed(10); nolog);
    ExpectEq(expected, err, "onStuffedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedWithoutValueReturnsFalse()
{
    ExpectFalse(Character.addStuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedCanAddToStuffedValue()
{
    ExpectEq(0, Character.Stuffed());
    ExpectTrue(Character.addStuffed(10));
    ExpectEq(10, Character.Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedCanRemoveFromStuffedValue()
{
    ExpectEq(10, Character.Stuffed(10));
    ExpectTrue(Character.addStuffed(-5));
    ExpectEq(5, Character.Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character.Stuffed(10));
    ExpectTrue(Character.addStuffed(-15));
    ExpectEq(0, Character.Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onStuffedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.addStuffed(10); nolog);
    ExpectEq(expected, err, "onStuffedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DruggedSetsDruggedLevel()
{
    ExpectEq(0, Character.Drugged());
    ExpectEq(10, Character.Drugged(10));
}

/////////////////////////////////////////////////////////////////////////////
void DruggedFiresOnDruggedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onDruggedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character.Drugged());

    string err = catch (Character.Drugged(10); nolog);
    ExpectEq(expected, err, "onDruggedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedWithoutValueReturnsFalse()
{
    ExpectFalse(Character.addDrugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedCanAddToDruggedValue()
{
    ExpectEq(0, Character.Drugged());
    ExpectTrue(Character.addDrugged(10));
    ExpectEq(10, Character.Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedCanRemoveFromDruggedValue()
{
    ExpectEq(10, Character.Drugged(10));
    ExpectTrue(Character.addDrugged(-5));
    ExpectEq(5, Character.Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character.Drugged(10));
    ExpectTrue(Character.addDrugged(-15));
    ExpectEq(0, Character.Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onDruggedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.addDrugged(10); nolog);
    ExpectEq(expected, err, "onDruggedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void SoakedSetsSoakedLevel()
{
    ExpectEq(0, Character.Soaked());
    ExpectEq(10, Character.Soaked(10));
}

/////////////////////////////////////////////////////////////////////////////
void SoakedFiresOnSoakedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onSoakedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character.Soaked());

    string err = catch (Character.Soaked(10); nolog);
    ExpectEq(expected, err, "onSoakedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedWithoutValueReturnsFalse()
{
    ExpectFalse(Character.addSoaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedCanAddToSoakedValue()
{
    ExpectEq(0, Character.Soaked());
    ExpectTrue(Character.addSoaked(10));
    ExpectEq(10, Character.Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedCanRemoveFromSoakedValue()
{
    ExpectEq(10, Character.Soaked(10));
    ExpectTrue(Character.addSoaked(-5));
    ExpectEq(5, Character.Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character.Soaked(10));
    ExpectTrue(Character.addSoaked(-15));
    ExpectEq(0, Character.Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onSoakedChanged called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.addSoaked(10); nolog);
    ExpectEq(expected, err, "onSoakedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholIncreasesIntoxication()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholAddsDrunkTrait()
{
    ExpectFalse(Character.isTraitOf("/lib/instances/traits/biological/drunk.c"));
    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectTrue(Character.isTraitOf("/lib/instances/traits/biological/drunk.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CanDrinkAlcoholToDunkedness()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Intoxicated());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 17);
    ExpectTrue(Character.drinkAlcohol(drink));

    ExpectEq(20, Character.Intoxicated());
    ExpectEq("You feel completely inebriated.\n", Character.caughtMessage());

    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholFiresOnDrunkWhenInebriated()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 20);

    string expected = "*event handler: onDrunk called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.drinkAlcohol(drink); nolog);
    ExpectEq(expected, err, "onDrunk called on subscriber");

    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholAfterDrunkFails()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Intoxicated());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 17);
    ExpectTrue(Character.drinkAlcohol(drink));

    ExpectEq(20, Character.Intoxicated());

    ExpectFalse(Character.drinkAlcohol(drink));
    ExpectEq("You fail to reach the drink with your mouth.\n", Character.caughtMessage());
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void SobrietyReturnsWhenIntoxIsZero()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Intoxicated());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", -5);
    ExpectTrue(Character.drinkAlcohol(drink));

    ExpectEq(0, Character.Intoxicated());
    ExpectEq("You are completely sober.\n", Character.caughtMessage());
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholFiresOnSoberWhenNoLongerInebriated()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onSober called, caller: /lib/tests/support/services/mockPlayer.c";
    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", -5);

    string err = catch (Character.drinkAlcohol(drink); nolog);
    ExpectEq(expected, err, "onSober called on subscriber");
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DetoxBeginsAfterIntox()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/kolsche.c")));
    Character.heart_beat();
    ExpectEq("You suddenly without reason get a bad headache.\n", Character.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DetoxFromAlcoholFiresOnBeginDetox()
{
    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/kolsche.c")));

    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onBeginDetox called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.heart_beat(); nolog);
    ExpectEq(expected, err, "onBeginDetox called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void HeadacheEndsAfterDetox()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/kolsche.c")));
    Character.heart_beat();
    Character.catch_tell("");
    for(int i = 0; i < 29; i++)
    {
        Character.heart_beat();
        ExpectTrue(Character.haveHeadache(), sprintf("Iteration %d\n", i));
    }
    ExpectEq("", Character.caughtMessage(), "No messages about detox sent");
    Character.heart_beat();
    ExpectEq("Your headache disappears.\n", Character.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnDetoxifiedFiresAfterDetox()
{
    ExpectEq(0, Character.Intoxicated());

    ExpectTrue(Character.drinkAlcohol(load_object("/lib/instances/items/drinks/kolsche.c")));
    Character.heart_beat();
    for (int i = 0; i < 29; i++)
    {
        Character.heart_beat();
        ExpectTrue(Character.haveHeadache(), sprintf("Iteration %d\n", i));
    }

    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onDetoxified called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.heart_beat(); nolog);
    ExpectEq(expected, err, "onDetoxified called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugIncreasesDrugged()
{
    ExpectEq(0, Character.Drugged());

    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 5);

    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(5, Character.Drugged());

    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void CanConsumeDrugToWasted()
{
    ExpectEq(0, Character.Drugged());

    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 5);

    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(5, Character.Drugged());

    drug.set("biological strength", 15);

    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(20, Character.Drugged());
    ExpectEq("You feel completely wasted.\n", Character.caughtMessage());

    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugAddsCorrectDruggedTrait()
{
    ExpectFalse(Character.isTraitOf("/lib/instances/traits/biological/wasted-on-opiates.c"));

    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 5);

    ExpectTrue(Character.consumeDrug(drug));   
    ExpectTrue(Character.isTraitOf("/lib/instances/traits/biological/wasted-on-opiates.c"));

    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugFiresOnWastedOnDrugsWhenWasted()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onWastedOnDrugs called, caller: /lib/tests/support/services/mockPlayer.c";
    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 20);

    string err = catch (Character.consumeDrug(drug); nolog);
    ExpectEq(expected, err, "onWastedOnDrugs called on subscriber");
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugAfterWastedFails()
{
    ExpectEq(0, Character.Drugged());
    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 5);

    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(5, Character.Drugged());

    drug.set("biological strength", 15);
    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(20, Character.Drugged());
    ExpectFalse(Character.consumeDrug(drug));
    ExpectEq("You fail to reach your mouth.\n", Character.caughtMessage());
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void HealthReturnsWhenDruggedIsZero()
{
    ExpectEq(0, Character.Drugged());
    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 5);

    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(5, Character.Drugged());

    drug.set("biological strength", -15);
    ExpectTrue(Character.consumeDrug(drug));
    ExpectEq(0, Character.Drugged());
    ExpectEq("You are completely free of drugs.\n", Character.caughtMessage());
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugFiresOnNoLongerDruggedWhenNoLongerDrugged()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onNoLongerDrugged called, caller: /lib/tests/support/services/mockPlayer.c";

    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", -5);

    string err = catch (Character.consumeDrug(drug); nolog);
    ExpectEq(expected, err, "onNoLongerDrugged called on subscriber");
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void DetoxBeginsAfterDrugged()
{
    ExpectEq(0, Character.Drugged());
    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 1);

    ExpectTrue(Character.consumeDrug(drug));
    Character.heart_beat();
    ExpectEq("You suddenly without reason get a bad headache.\n", Character.caughtMessage());
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void DetoxFromDrugsFiresOnBeginDetox()
{
    object drug = clone_object("/lib/items/food.c");
    drug.set("biological effect", "opiate");
    drug.set("biological strength", 1);

    ExpectTrue(Character.consumeDrug(drug));

    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onBeginDetox called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.heart_beat(); nolog);
    ExpectEq(expected, err, "onBeginDetox called on subscriber");
    destruct(drug);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkIncreasesSoaked()
{
    ExpectEq(0, Character.Soaked());

    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void CanDrinkToSoaked()
{
    ExpectEq(0, Character.Soaked());

    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Soaked());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 17);
    ExpectTrue(Character.drink(drink));

    ExpectEq(20, Character.Soaked());
    ExpectEq("You feel like your bladder is going to explode.\n", Character.caughtMessage());
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkFiresOnSoakedWhenTooMuchHasBeenDrunk()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onSoaked called, caller: /lib/tests/support/services/mockPlayer.c";

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 17);

    string err = catch (Character.drink(drink); nolog);
    ExpectEq(expected, err, "onSoaked called on subscriber");
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAfterSoakedFails()
{
    ExpectEq(0, Character.Soaked());

    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Soaked());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", 17);

    ExpectTrue(Character.drink(drink));
    ExpectEq(20, Character.Soaked());
    ExpectFalse(Character.drink(drink));
    ExpectEq("You can't possibly drink that much right now!\nYou feel crosslegged enough as it is.\n",
        Character.caughtMessage());

    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void ThirstReturnsWhenSoakedIsZero()
{
    ExpectEq(0, Character.Soaked());

    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/trippel.c")));
    ExpectEq(3, Character.Soaked());

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", -10);

    ExpectTrue(Character.drink(drink));
    ExpectEq(0, Character.Soaked());
    ExpectEq("You feel a bit dry in the mouth.\n", Character.caughtMessage());
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void DrinkFiresOnNoLongerSoakedWhenNoLongerSoaked()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onNoLongerSoaked called, caller: /lib/tests/support/services/mockPlayer.c";

    object drink = clone_object("/lib/instances/items/drinks/trippel.c");
    drink.set("biological strength", -10);

    string err = catch (Character.drink(drink); nolog);
    ExpectEq(expected, err, "onNoLongerSoaked called on subscriber");
    destruct(drink);
}

/////////////////////////////////////////////////////////////////////////////
void ThirstBeginsAfterSoaked()
{
    ExpectEq(0, Character.Soaked());

    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/kolsche.c")));
    Character.heart_beat();
    ExpectEq("You feel a bit dry in the mouth.\n", Character.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoLongerSoakedFiresOnNoLongerSoaked()
{
    ExpectTrue(Character.drink(load_object("/lib/instances/items/drinks/kolsche.c")));

    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onNoLongerSoaked called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.heart_beat(); nolog);
    ExpectEq(expected, err, "onNoLongerSoaked called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void EatIncreasesStuffed()
{
    ExpectEq(0, Character.Stuffed());

    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 5);

    ExpectTrue(Character.eat(food));
    ExpectEq(5, Character.Stuffed());
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void CanEatToStuffed()
{
    ExpectEq(0, Character.Stuffed());

    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 5);

    ExpectTrue(Character.eat(food));
    ExpectEq(5, Character.Stuffed());

    food.set("biological strength", 15);

    ExpectTrue(Character.eat(food));
    ExpectEq(20, Character.Stuffed());
    ExpectEq("You feel full.\n", Character.caughtMessage());
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void EatFiresOnStuffedWhenTooMuchHasBeenEaten()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onCannotEatMore called, caller: /lib/tests/support/services/mockPlayer.c";

    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 20);

    string err = catch (Character.eat(food); nolog);
    ExpectEq(expected, err, "onCannotEatMore called on subscriber");
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void EatAfterStuffedFails()
{
    ExpectEq(0, Character.Stuffed());
    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 5);

    ExpectTrue(Character.eat(food));
    ExpectEq(5, Character.Stuffed());

    food.set("biological strength", 15);

    ExpectTrue(Character.eat(food));
    ExpectEq(20, Character.Stuffed());
    ExpectFalse(Character.eat(food));
    ExpectEq("This is much too rich for you right now! Perhaps something lighter?\n",
        Character.caughtMessage());
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void HealthReturnsWhenStuffedIsZero()
{
    ExpectEq(0, Character.Stuffed());
    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 5);

    ExpectTrue(Character.eat(food));
    ExpectEq(5, Character.Stuffed());

    food.set("biological strength", -10);

    ExpectTrue(Character.eat(food));
    ExpectEq(0, Character.Stuffed());
    ExpectEq("Your stomach makes a rumbling sound.\n", Character.caughtMessage());
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void EatFiresOnHungryWhenNoLongerStuffed()
{
    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onHungry called, caller: /lib/tests/support/services/mockPlayer.c";

    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", -5);

    string err = catch (Character.eat(food); nolog);
    ExpectEq(expected, err, "onHungry called on subscriber");
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void HungerBeginsAfterStuffed()
{
    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 1);
    ExpectTrue(Character.eat(food));
    Character.heart_beat();
    ExpectEq("Your stomach makes a rumbling sound.\n", Character.caughtMessage());
    destruct(food);
}

/////////////////////////////////////////////////////////////////////////////
void NoLongerStuffedFiresOnHungry()
{
    object food = clone_object("/lib/items/food.c");
    food.set("biological strength", 1);
    ExpectTrue(Character.eat(food));


    object subscriber = clone_object("/lib/tests/support/events/mockBiologicalSubscriber");
    Character.registerEvent(subscriber);

    string expected = "*event handler: onHungry called, caller: /lib/tests/support/services/mockPlayer.c";

    string err = catch (Character.heart_beat(); nolog);
    ExpectEq(expected, err, "onHungry called on subscriber");
    destruct(food);
}
