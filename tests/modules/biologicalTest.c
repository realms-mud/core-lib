//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Character;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Character = clone_object("/lib/tests/support/services/mockPlayer");
    Character->Name("Bob");
    Character->Con(5);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Character);
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedSetsIntoxicationLevel()
{
    ExpectEq(0, Character->Intoxicated());
    ExpectEq(10, Character->Intoxicated(10));
}

/////////////////////////////////////////////////////////////////////////////
void IntoxicatedFiresOnIntoxicationChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character->Intoxicated());

    string err = catch (Character->Intoxicated(10));
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationWithoutValueReturnsFalse()
{
    ExpectFalse(Character->addIntoxication());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanAddToIntoxValue()
{
    ExpectEq(0, Character->Intoxicated());
    ExpectTrue(Character->addIntoxication(10));
    ExpectEq(10, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationCanRemoveFromIntoxValue()
{
    ExpectEq(10, Character->Intoxicated(10));
    ExpectTrue(Character->addIntoxication(-5));
    ExpectEq(5, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character->Intoxicated(10));
    ExpectTrue(Character->addIntoxication(-15));
    ExpectEq(0, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void AddIntoxicationFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onIntoxicationChanged called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->addIntoxication(10));
    ExpectEq(expected, err, "onIntoxicationChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void StuffedSetsStuffedLevel()
{
    ExpectEq(0, Character->Stuffed());
    ExpectEq(10, Character->Stuffed(10));
}

/////////////////////////////////////////////////////////////////////////////
void StuffedFiresOnStuffedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onStuffedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character->Stuffed());

    string err = catch (Character->Stuffed(10));
    ExpectEq(expected, err, "onStuffedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedWithoutValueReturnsFalse()
{
    ExpectFalse(Character->addStuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedCanAddToStuffedValue()
{
    ExpectEq(0, Character->Stuffed());
    ExpectTrue(Character->addStuffed(10));
    ExpectEq(10, Character->Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedCanRemoveFromStuffedValue()
{
    ExpectEq(10, Character->Stuffed(10));
    ExpectTrue(Character->addStuffed(-5));
    ExpectEq(5, Character->Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character->Stuffed(10));
    ExpectTrue(Character->addStuffed(-15));
    ExpectEq(0, Character->Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void AddStuffedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onStuffedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->addStuffed(10));
    ExpectEq(expected, err, "onStuffedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DruggedSetsDruggedLevel()
{
    ExpectEq(0, Character->Drugged());
    ExpectEq(10, Character->Drugged(10));
}

/////////////////////////////////////////////////////////////////////////////
void DruggedFiresOnDruggedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onDruggedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character->Drugged());

    string err = catch (Character->Drugged(10));
    ExpectEq(expected, err, "onDruggedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedWithoutValueReturnsFalse()
{
    ExpectFalse(Character->addDrugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedCanAddToDruggedValue()
{
    ExpectEq(0, Character->Drugged());
    ExpectTrue(Character->addDrugged(10));
    ExpectEq(10, Character->Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedCanRemoveFromDruggedValue()
{
    ExpectEq(10, Character->Drugged(10));
    ExpectTrue(Character->addDrugged(-5));
    ExpectEq(5, Character->Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character->Drugged(10));
    ExpectTrue(Character->addDrugged(-15));
    ExpectEq(0, Character->Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void AddDruggedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onDruggedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->addDrugged(10));
    ExpectEq(expected, err, "onDruggedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void SoakedSetsSoakedLevel()
{
    ExpectEq(0, Character->Soaked());
    ExpectEq(10, Character->Soaked(10));
}

/////////////////////////////////////////////////////////////////////////////
void SoakedFiresOnSoakedChangedEventWhenValueChanges()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onSoakedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    ExpectEq(0, Character->Soaked());

    string err = catch (Character->Soaked(10));
    ExpectEq(expected, err, "onSoakedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedWithoutValueReturnsFalse()
{
    ExpectFalse(Character->addSoaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedCanAddToSoakedValue()
{
    ExpectEq(0, Character->Soaked());
    ExpectTrue(Character->addSoaked(10));
    ExpectEq(10, Character->Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedCanRemoveFromSoakedValue()
{
    ExpectEq(10, Character->Soaked(10));
    ExpectTrue(Character->addSoaked(-5));
    ExpectEq(5, Character->Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedNeverDoesNotSetValueBelowZero()
{
    ExpectEq(10, Character->Soaked(10));
    ExpectTrue(Character->addSoaked(-15));
    ExpectEq(0, Character->Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void AddSoakedFiresOnIntoxicationChangedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onSoakedChanged called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->addSoaked(10));
    ExpectEq(expected, err, "onSoakedChanged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholIncreasesIntoxication()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(5));
    ExpectEq(5, Character->Intoxicated());
}

/////////////////////////////////////////////////////////////////////////////
void CanDrinkAlcoholToDunkedness()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(5));
    ExpectEq(5, Character->Intoxicated());
    ExpectTrue(Character->drinkAlcohol(15));
    ExpectEq(20, Character->Intoxicated());
    ExpectEq("You feel completely inebriated.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholFiresOnDrunkWhenInebriated()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onDrunk called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->drinkAlcohol(20));
    ExpectEq(expected, err, "onDrunk called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholAfterDrunkFails()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(5));
    ExpectEq(5, Character->Intoxicated());
    ExpectTrue(Character->drinkAlcohol(15));
    ExpectEq(20, Character->Intoxicated());
    ExpectFalse(Character->drinkAlcohol(15));
    ExpectEq("You fail to reach the drink with your mouth.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SobrietyReturnsWhenIntoxIsZero()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(5));
    ExpectEq(5, Character->Intoxicated());
    ExpectTrue(Character->drinkAlcohol(-15));
    ExpectEq(0, Character->Intoxicated());
    ExpectEq("You are completely sober.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAlcoholFiresOnSoberWhenNoLongerInebriated()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onSober called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->drinkAlcohol(-20));
    ExpectEq(expected, err, "onSober called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DetoxBeginsAfterIntox()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(1));
    Character->heart_beat();
    ExpectEq("You suddenly without reason get a bad headache.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DetoxFromAlcoholFiresOnBeginDetox()
{
    ExpectTrue(Character->drinkAlcohol(1));

    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onBeginDetox called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->heart_beat());
    ExpectEq(expected, err, "onBeginDetox called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void HeadacheEndsAfterDetox()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(1));
    Character->heart_beat();
    Character->catch_tell("");
    for(int i = 0; i < 29; i++)
    {
        Character->heart_beat();
        ExpectTrue(Character->haveHeadache(), sprintf("Iteration %d\n", i));
    }
    ExpectEq("", Character->caughtMessage(), "No messages about detox sent");
    Character->heart_beat();
    ExpectEq("Your headache disappears.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnDetoxifiedFiresAfterDetox()
{
    ExpectEq(0, Character->Intoxicated());

    ExpectTrue(Character->drinkAlcohol(1));
    Character->heart_beat();
    for (int i = 0; i < 29; i++)
    {
        Character->heart_beat();
        ExpectTrue(Character->haveHeadache(), sprintf("Iteration %d\n", i));
    }

    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onDetoxified called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->heart_beat());
    ExpectEq(expected, err, "onDetoxified called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugIncreasesDrugged()
{
    ExpectEq(0, Character->Drugged());

    ExpectTrue(Character->consumeDrug(5));
    ExpectEq(5, Character->Drugged());
}

/////////////////////////////////////////////////////////////////////////////
void CanConsumeDrugToWasted()
{
    ExpectEq(0, Character->Drugged());

    ExpectTrue(Character->consumeDrug(5));
    ExpectEq(5, Character->Drugged());
    ExpectTrue(Character->consumeDrug(15));
    ExpectEq(20, Character->Drugged());
    ExpectEq("You feel completely wasted.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugFiresOnWastedOnDrugsWhenWasted()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onWastedOnDrugs called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->consumeDrug(20));
    ExpectEq(expected, err, "onWastedOnDrugs called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugAfterWastedFails()
{
    ExpectEq(0, Character->Drugged());

    ExpectTrue(Character->consumeDrug(5));
    ExpectEq(5, Character->Drugged());
    ExpectTrue(Character->consumeDrug(15));
    ExpectEq(20, Character->Drugged());
    ExpectFalse(Character->consumeDrug(15));
    ExpectEq("You fail to reach your mouth.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthReturnsWhenDruggedIsZero()
{
    ExpectEq(0, Character->Drugged());

    ExpectTrue(Character->consumeDrug(5));
    ExpectEq(5, Character->Drugged());
    ExpectTrue(Character->consumeDrug(-15));
    ExpectEq(0, Character->Drugged());
    ExpectEq("You are completely free of drugs.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConsumeDrugFiresOnNoLongerDruggedWhenNoLongerDrugged()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onNoLongerDrugged called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->consumeDrug(-20));
    ExpectEq(expected, err, "onNoLongerDrugged called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DetoxBeginsAfterDrugged()
{
    ExpectEq(0, Character->Drugged());

    ExpectTrue(Character->consumeDrug(1));
    Character->heart_beat();
    ExpectEq("You suddenly without reason get a bad headache.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DetoxFromDrugsFiresOnBeginDetox()
{
    ExpectTrue(Character->consumeDrug(1));

    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onBeginDetox called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->heart_beat());
    ExpectEq(expected, err, "onBeginDetox called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DrinkIncreasesSoaked()
{
    ExpectEq(0, Character->Soaked());

    ExpectTrue(Character->drink(5));
    ExpectEq(5, Character->Soaked());
}

/////////////////////////////////////////////////////////////////////////////
void CanDrinkToSoaked()
{
    ExpectEq(0, Character->Soaked());

    ExpectTrue(Character->drink(5));
    ExpectEq(5, Character->Soaked());
    ExpectTrue(Character->drink(15));
    ExpectEq(20, Character->Soaked());
    ExpectEq("You feel like your bladder is going to explode.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DrinkFiresOnSoakedWhenTooMuchHasBeenDrunk()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onSoaked called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->drink(20));
    ExpectEq(expected, err, "onSoaked called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DrinkAfterSoakedFails()
{
    ExpectEq(0, Character->Soaked());

    ExpectTrue(Character->drink(5));
    ExpectEq(5, Character->Soaked());
    ExpectTrue(Character->drink(15));
    ExpectEq(20, Character->Soaked());
    ExpectFalse(Character->drink(15));
    ExpectEq("You can't possibly drink that much right now!\nYou feel crosslegged enough as it is.\n",
        Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThirstReturnsWhenSoakedIsZero()
{
    ExpectEq(0, Character->Soaked());

    ExpectTrue(Character->drink(5));
    ExpectEq(5, Character->Soaked());
    ExpectTrue(Character->drink(-15));
    ExpectEq(0, Character->Soaked());
    ExpectEq("You feel a bit dry in the mouth.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DrinkFiresOnNoLongerSoakedWhenNoLongerSoaked()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onNoLongerSoaked called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->drink(-20));
    ExpectEq(expected, err, "onNoLongerSoaked called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void ThirstBeginsAfterSoaked()
{
    ExpectEq(0, Character->Soaked());

    ExpectTrue(Character->drink(1));
    Character->heart_beat();
    ExpectEq("You feel a bit dry in the mouth.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoLongerSoakedFiresOnNoLongerSoaked()
{
    ExpectTrue(Character->drink(1));

    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onNoLongerSoaked called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->heart_beat());
    ExpectEq(expected, err, "onNoLongerSoaked called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void EatIncreasesStuffed()
{
    ExpectEq(0, Character->Stuffed());

    ExpectTrue(Character->eat(5));
    ExpectEq(5, Character->Stuffed());
}

/////////////////////////////////////////////////////////////////////////////
void CanEatToStuffed()
{
    ExpectEq(0, Character->Stuffed());

    ExpectTrue(Character->eat(5));
    ExpectEq(5, Character->Stuffed());
    ExpectTrue(Character->eat(15));
    ExpectEq(20, Character->Stuffed());
    ExpectEq("You feel full.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EatFiresOnStuffedWhenTooMuchHasBeenEaten()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onCannotEatMore called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->eat(20));
    ExpectEq(expected, err, "onCannotEatMore called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void EatAfterStuffedFails()
{
    ExpectEq(0, Character->Stuffed());

    ExpectTrue(Character->eat(5));
    ExpectEq(5, Character->Stuffed());
    ExpectTrue(Character->eat(15));
    ExpectEq(20, Character->Stuffed());
    ExpectFalse(Character->eat(15));
    ExpectEq("This is much too rich for you right now! Perhaps something lighter?\n",
        Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthReturnsWhenStuffedIsZero()
{
    ExpectEq(0, Character->Stuffed());

    ExpectTrue(Character->eat(5));
    ExpectEq(5, Character->Stuffed());
    ExpectTrue(Character->eat(-15));
    ExpectEq(0, Character->Stuffed());
    ExpectEq("Your stomach makes a rumbling sound.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EatFiresOnHungryWhenNoLongerStuffed()
{
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onHungry called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->eat(-20));
    ExpectEq(expected, err, "onHungry called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void HungerBeginsAfterStuffed()
{
    ExpectTrue(Character->eat(1));
    Character->heart_beat();
    ExpectEq("Your stomach makes a rumbling sound.\n", Character->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoLongerStuffedFiresOnHungry()
{
    ExpectTrue(Character->eat(1));

    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Character->registerEvent(subscriber);

    string expected = "*event handler: onHungry called, caller: lib/tests/support/services/mockPlayer.c";

    string err = catch (Character->heart_beat());
    ExpectEq(expected, err, "onHungry called on subscriber");
}