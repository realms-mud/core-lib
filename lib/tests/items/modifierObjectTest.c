//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Modifier;
object *Targets;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Modifier = clone_object("/lib/items/modifierObject");

    Targets = ({
        clone_object("/lib/tests/support/services/mockUserWithInventory.c"),
        clone_object("/lib/tests/support/services/mockUserWithInventory.c")
    });
    Targets[0]->Name("Bob");
    Targets[1]->Name("Fred");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Targets[0]);
    destruct(Targets[1]);
    Targets = ({});

    destruct(Modifier);
}

/////////////////////////////////////////////////////////////////////////////
void ModifierPropertiesCanBeSet()
{
    // Only test a few of these - the full set is tested in items/itemTest
    ExpectTrue(Modifier->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectEq(5, Modifier->query("bonus armor class"), "bonus armor class query returns correctly");

    ExpectTrue(Modifier->set("charges", 5), "charges can be set");
    ExpectEq(5, Modifier->query("charges"), "5 charges were returned");

    ExpectTrue(Modifier->set("no sell", 1), "no sell can be set");
    ExpectEq(1, Modifier->query("no sell"), "1 no sell was returned");

    ExpectTrue(Modifier->set("name", "blah"), "name can be set");
    ExpectEq("blah", Modifier->query("name"), "'blah' name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void PenaltiesCanBeSet()
{
    ExpectTrue(Modifier->set("penalty to armor class", 2), "penalty to armor class can be set");
    ExpectEq(-2, Modifier->query("bonus armor class"), "bonus armor class query returns correctly");

    ExpectTrue(Modifier->set("penalty to long sword", 5), "penalty to long sword can be set");
    ExpectEq(-5, Modifier->query("bonus long sword"), "bonus long sword query returns correctly");

    ExpectTrue(Modifier->set("penalty to strength", 1), "penalty to strength can be set");
    ExpectEq(-1, Modifier->query("bonus strength"), "bonus strength query returns correctly");
}


/////////////////////////////////////////////////////////////////////////////
void CanSetFullyQualifiedName()
{
    ExpectTrue(Modifier->set("fully qualified name", "blah"), "fully qualified name can be set");
    ExpectEq("blah", Modifier->query("fully qualified name"), "'blah' fully qualified name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void FullyQualifiedNameReturnsCorrectly()
{
    ExpectEq("/lib/items/modifierObject.c", Modifier->fullyQualifiedName(), "default fully qualified name was returned");
    ExpectTrue(Modifier->set("fully qualified name", "blah"), "fully qualified name can be set");
    ExpectEq("blah", Modifier->fullyQualifiedName(), "'blah' fully qualified name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidFullyQualifiedNameThrowsError()
{
    string expected = "*modifierObject: The passed 'fully qualified name' must be a string.\n";

    string err = catch (Modifier->set("fully qualified name", 1));
    ExpectEq(expected, err, "fully qualified name cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetRegistrationList()
{
    Modifier->set("fully qualified name", "blah");

    ExpectEq(2, Modifier->set("registration list", Targets), "registration list can be set");
    ExpectEq(2, sizeof(Modifier->query("registration list")), "2 items in registration list was returned");
    
    object target = Modifier->query("registration list")[0];
    ExpectEq("Bob", target->Name(), "'Bob' is in registration list");
    ExpectEq("blah", target->registeredInventoryObject("blah")->query("fully qualified name"), "modifier with correct FQN is registered with 'Bob'");

    target = Modifier->query("registration list")[1];
    ExpectEq("Fred", target->Name(), "'Fred' is in registration list");
    ExpectEq("blah", target->registeredInventoryObject("blah")->query("fully qualified name"), "modifier with correct FQN is registered with 'Fred'");
}

/////////////////////////////////////////////////////////////////////////////
void CanRegisterModifierWithTargetList()
{
    Modifier->set("fully qualified name", "blah");

    ExpectEq(2, Modifier->registerModifierWithTargetList(Targets), "registration list can be set");
    ExpectEq(2, sizeof(Modifier->query("registration list")), "2 items in registration list was returned");
}

/////////////////////////////////////////////////////////////////////////////
void CanUnregisterModifierWithTargetList()
{
    Modifier->set("fully qualified name", "blah");

    ExpectFalse(Modifier->unregisterModifierFromTargetList(), "unregister returns false when empty");
    ExpectEq(2, Modifier->registerModifierWithTargetList(Targets), "registration list can be set");
    ExpectEq(2, sizeof(Modifier->query("registration list")), "2 items in registration list was returned");
    ExpectTrue(Targets[0]->registeredInventoryObject("blah"), "modifier object not in 'Bob'");
    ExpectTrue(Targets[1]->registeredInventoryObject("blah"), "modifier object not in 'Bob'");

    ExpectTrue(Modifier->unregisterModifierFromTargetList(), "unregister returns false when empty");
    ExpectEq(0, sizeof(Modifier->query("registration list")), "0 items in registration list after unregister");
    ExpectFalse(Targets[0]->registeredInventoryObject("blah"), "modifier object not in 'Bob'");
    ExpectFalse(Targets[1]->registeredInventoryObject("blah"), "modifier object not in 'Bob'");
}

/////////////////////////////////////////////////////////////////////////////
void DropAlwaysReturnsOne()
{
    ExpectEq(1, Modifier->drop(), "drop returns 1");
}
