//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Item;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Item = clone_object("/lib/items/item");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Item);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetBonusesOnItems()
{
    // Only test a few of these - the full set is tested in dictionaries/bonusesDictionaryTest
    ExpectFalse(Item->query("enchanted"), "item is enchanted");
    ExpectTrue(Item->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectTrue(Item->set("bonus fire attack", 1), "bonus fire attack can be set");
    ExpectTrue(Item->set("bonus gem crafting", 7), "bonus armor class can be set");

    ExpectEq(5, Item->query("bonus armor class"), "bonus armor class query returns correctly");
    ExpectEq(1, Item->query("bonus fire attack"), "bonus fire attack query returns correctly");
    ExpectEq(7, Item->query("bonus gem crafting"), "bonus gem crafting query returns correctly");
    ExpectTrue(Item->query("enchanted"), "item is enchanted");
}

/////////////////////////////////////////////////////////////////////////////
void QueryingBonusesReturnsAllAddedBonuses()
{
    Item->set("weight", 3);
    Item->set("material", "galvorn");

    ExpectTrue(Item->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectEq(({ "bonus armor class" }), Item->query("bonuses"));

    ExpectTrue(Item->set("bonus fire attack", 1), "bonus fire attack can be set");
    ExpectEq(({ "bonus armor class", "bonus fire attack" }), Item->query("bonuses"));

    ExpectTrue(Item->set("bonus gem crafting", 7), "bonus armor class can be set");
    ExpectEq(({ "bonus armor class", "bonus fire attack", "bonus gem crafting" }), Item->query("bonuses"));

    ExpectTrue(Item->set("bonus attack", 7), "bonus armor class can be set");
    ExpectEq(({ "bonus attack", "bonus armor class", "bonus fire attack", "bonus gem crafting" }), Item->query("bonuses"));
}

/////////////////////////////////////////////////////////////////////////////
void QueryingUnsetValueCorrectlyReturns()
{
    ExpectFalse(Item->query("bonus armor class"), "bonus armor class query when unset returns false");
    ExpectFalse(Item->query("alias"), "alias query when unset returns correctly");
    ExpectFalse(Item->query("charges"), "charges query when unset returns correctly");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidBonusesThrowError()
{
    string err = catch(Item->set("bonus blarg", 5));
    string expectedError = "*Item: The 'bonus <thing>' element must be a string as defined in the keys of the bonusList mapping in /lib/dictionaries/bonusesDictionary.c and it must be set to an appropriate value.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid bonuses");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAliasesOnItems()
{
    ExpectTrue(Item->set("aliases", ({ "test", "blah" })), "aliases can be set");
    ExpectEq(2, sizeof(Item->query("aliases")), "Two aliases were returned");
    ExpectEq("test", Item->query("aliases")[0], "The first alias is 'test'");
    ExpectEq("blah", Item->query("aliases")[1], "The first alias is 'blah'");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAliasThrowsError()
{
    string expected = "*Item: The passed 'aliases' data must be an array of strings.\n";

    string err = catch (Item->set("aliases", 1));
    ExpectEq(expected, err, "aliases cannot be integers");

    err = catch (Item->set("aliases", "blah"));
    ExpectEq(expected, err, "aliases cannot be simple strings");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetChargesOnItems()
{
    ExpectTrue(Item->set("charges", 5), "charges can be set");
    ExpectEq(5, Item->query("charges"), "5 charges were returned");
    ExpectTrue(Item->query("charged"), "charged returns true");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidChargesThrowsError()
{
    string expected = "*Item: The passed 'charges' data must be an integer greater than 0.\n";

    string err = catch (Item->set("charges", -1));
    ExpectEq(expected, err, "charges cannot be negative");

    err = catch (Item->set("charges", "blah"));
    ExpectEq(expected, err, "charges cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetCraftsmanshipOnItems()
{
    ExpectTrue(Item->set("craftsmanship", 8), "craftsmanship can be set");
    ExpectEq(8, Item->query("craftsmanship"), "8 craftsmanship was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidCraftsmanshipThrowsError()
{
    string expected = "*Item: The passed 'craftsmanship' data must be an integer greater than 0.\n";

    string err = catch (Item->set("craftsmanship", -1));
    ExpectEq(expected, err, "craftsmanship cannot be negative");

    err = catch (Item->set("craftsmanship", "blah"));
    ExpectEq(expected, err, "craftsmanship cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetValueOnItems()
{
    ExpectTrue(Item->set("value", 850), "value can be set");
    ExpectEq(850, Item->query("value"), "850 value was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidValueThrowsError()
{
    string expected = "*Item: The passed 'value' data must be an integer.\n";

    string err = catch (Item->set("value", "blah"));
    ExpectEq(expected, err, "value cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetWeightOnItems()
{
    ExpectTrue(Item->set("weight", 2), "weight can be set");
    ExpectEq(2, Item->query("weight"), "2 weight was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidWeightThrowsError()
{
    string expected = "*Item: The passed 'weight' data must be an integer.\n";

    string err = catch (Item->set("weight", "blah"));
    ExpectEq(expected, err, "weight cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEncumberanceOnItems()
{
    ExpectTrue(Item->set("encumberance", 2), "weight can be set");
    ExpectEq(2, Item->query("encumberance"), "2 weight was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidEncumberanceThrowsError()
{
    string expected = "*Item: The passed 'encumberance' data must be an integer.\n";

    string err = catch (Item->set("encumberance", "blah"));
    ExpectEq(expected, err, "encumberance cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNoStealOnItems()
{
    ExpectTrue(Item->set("no steal", 1), "no steal can be set");
    ExpectEq(1, Item->query("no steal"), "1 no steal was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidNoStealThrowsError()
{
    string expected = "*Item: The passed 'no steal' data must be an integer.\n";

    string err = catch (Item->set("no steal", "blah"));
    ExpectEq(expected, err, "no steal cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNoSellOnItems()
{
    ExpectTrue(Item->set("no sell", 1), "no sell can be set");
    ExpectEq(1, Item->query("no sell"), "1 no sell was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidNoSellThrowsError()
{
    string expected = "*Item: The passed 'no sell' data must be an integer.\n";

    string err = catch (Item->set("no sell", "blah"));
    ExpectEq(expected, err, "no sell cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetRegisterEventHandlerOnItems()
{
    ExpectTrue(Item->set("register event handler", 1), "register event handler can be set");
    ExpectEq(1, Item->query("register event handler"), "1 register event handler was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidRegisterEventHandlerThrowsError()
{
    string expected = "*Item: The passed 'register event handler' data must be an integer.\n";

    string err = catch (Item->set("register event handler", "blah"));
    ExpectEq(expected, err, "register event handler cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLightOnItems()
{
    ExpectTrue(Item->set("light", 2), "light can be set");
    ExpectEq(2, Item->query("light"), "2 light was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidLightThrowsError()
{
    string expected = "*Item: The passed 'light' data must be an integer.\n";

    string err = catch (Item->set("light", "blah"));
    ExpectEq(expected, err, "light cannot be a string");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetInfoOnItems()
{
    ExpectTrue(Item->set("info", "blah"), "info can be set");
    ExpectEq("blah", Item->query("info"), "'blah' info was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidInfoThrowsError()
{
    string expected = "*Item: The passed 'info' data must be a string.\n";

    string err = catch (Item->set("info", 1));
    ExpectEq(expected, err, "info cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLongOnItems()
{
    ExpectTrue(Item->set("long", "blah"), "long can be set");
    ExpectEq("blah", Item->query("long"), "'blah' long was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidLongThrowsError()
{
    string expected = "*Item: The passed 'long' data must be a string.\n";

    string err = catch (Item->set("long", 1));
    ExpectEq(expected, err, "long cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAdditionalLongOnItems()
{
    ExpectTrue(Item->set("additional long", "blah"), "additional long can be set");
    ExpectEq("blah", Item->query("additional long"), "'blah' additional long was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidAdditionalLongThrowsError()
{
    string expected = "*Item: The passed 'additional long' data must be a string.\n";

    string err = catch (Item->set("additional long", 1));
    ExpectEq(expected, err, "additional long cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetUserDescriptionOnItems()
{
    ExpectTrue(Item->set("user description", "blah"), "user description can be set");
    ExpectEq("blah", Item->query("user description"), "'blah' user description was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidUserDescriptionThrowsError()
{
    string expected = "*Item: The passed 'user description' data must be a string.\n";

    string err = catch (Item->set("user description", 1));
    ExpectEq(expected, err, "user description cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNameOnItems()
{
    ExpectTrue(Item->set("name", "blah"), "name can be set");
    ExpectEq("blah", Item->query("name"), "'blah' name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidNameThrowsError()
{
    string expected = "*Item: The passed 'name' data must be a string.\n";

    string err = catch (Item->set("name", 1));
    ExpectEq(expected, err, "name cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetOwnerOnItems()
{
    ExpectTrue(Item->set("owner", "blah"), "owner can be set");
    ExpectEq("blah", Item->query("owner"), "'blah' owner was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidOwnerThrowsError()
{
    string expected = "*Item: The passed 'owner' data must be a string.\n";

    string err = catch (Item->set("owner", 1));
    ExpectEq(expected, err, "owner cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetReadMessageUnidentifiedOnItems()
{
    ExpectTrue(Item->set("read message unidentified", "blah"), "read message unidentified can be set");
    ExpectEq("blah", Item->query("read message unidentified"), "'blah' read message unidentified was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidReadMessageUnidentifiedThrowsError()
{
    string expected = "*Item: The passed 'read message unidentified' data must be a string.\n";

    string err = catch (Item->set("read message unidentified", 1));
    ExpectEq(expected, err, "read message unidentified cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetReadMessageIdentifiedOnItems()
{
    ExpectTrue(Item->set("read message identified", "blah"), "read message identified can be set");
    ExpectEq("blah", Item->query("read message identified"), "'blah' read message identified was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidReadMessageIdentifiedThrowsError()
{
    string expected = "*Item: The passed 'read message identified' data must be a string.\n";

    string err = catch (Item->set("read message identified", 1));
    ExpectEq(expected, err, "read message identified cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetShortOnItems()
{
    ExpectTrue(Item->set("short", "blah"), "short can be set");
    ExpectEq("blah", Item->query("short"), "'blah' short was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidShortThrowsError()
{
    string expected = "*Item: The passed 'short' data must be a string.\n";

    string err = catch (Item->set("short", 1));
    ExpectEq(expected, err, "short cannot be an integer");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetDestructMethodOnItems()
{
    ExpectTrue(Item->set("destruct method", "query"), "destruct method can be set");
    ExpectEq("query", Item->query("destruct method"), "'query' destruct method was returned");
}

/////////////////////////////////////////////////////////////////////////////
void DestructMethodMustExistOnObjectToBeSet()
{
    string expected = "*Item: The passed 'blah' destruct method must be a function that exists in this item.\n";

    string err = catch (Item->set("destruct method", "blah"));
    ExpectEq(expected, err, "destruct method must exist on the item");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMaterialOnItems()
{
    ExpectTrue(Item->set("material", "mithril"), "material can be set");
    ExpectEq("mithril", Item->query("material"), "'mithril' material was returned");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidMaterialThrowsError()
{
    string expected = "*Item: The 'material' element must be a string as defined in the keys of the materials mapping in /lib/dictionaries/materialsDictionary.c.\n";

    string err = catch (Item->set("material", "blah"));
    ExpectEq(expected, err, "material must be a valid material");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetEnchantmentsOnItems()
{
    ExpectTrue(Item->set("enchantments", ([ "fire": 10 ])), "enchantments can be set");
    ExpectEq(10, Item->query("enchantments")["fire"], "'fire' enchantment with a 10 damage was returned");
}

/////////////////////////////////////////////////////////////////////////////
void EnchantmentsSetEnchantedFlag()
{
    ExpectTrue(Item->set("enchantments", (["fire":10])), "enchantments can be set");
    ExpectTrue(Item->query("enchanted"), "item is enchanted");
}

/////////////////////////////////////////////////////////////////////////////
void SettingMalformedEnchantmentReturnsFalse()
{
    ExpectFalse(Item->set("enchantments", "blah"), "malformed enchantments cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidEnchantmentsThrowsError()
{
    string expected = "*Item: The enchantments element must be a mapping containing a valid damage type with a valid range as defined in /lib/dictionaries/attacksDictionary.c";

    string err = catch (Item->set("enchantments", (["gelatin":10])));
    ExpectEq(expected, err, "enchantments must be a valid enchantment");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetResistancesOnItems()
{
    ExpectTrue(Item->set("resistances", (["fire":10, "acid":20 ])), "resistances can be set");

    ExpectEq(10, Item->query("resistances")["fire"], "'fire' resistance with a 10 was returned");
    ExpectEq(20, Item->query("resistances")["acid"], "'acid' resistance with a 20 was returned");
}

/////////////////////////////////////////////////////////////////////////////
void ResistancesSetEnchantedFlag()
{
    ExpectTrue(Item->set("resistances", (["fire":10, "acid" : 20])), "resistances can be set");
    ExpectTrue(Item->query("enchanted"), "item is enchanted");
}

/////////////////////////////////////////////////////////////////////////////
void SettingMalformedResistancesReturnsFalse()
{
    ExpectFalse(Item->set("resistances", "blah"), "malformed resistances cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidResistancesThrowsError()
{
    string expected = "*Item: The resistances element must be a mapping containing a valid damage type with a valid range as defined in /lib/dictionaries/attacksDictionary.c";

    string err = catch (Item->set("resistances", ([ "gelatin":10 ])));
    ExpectEq(expected, err, "resistances must be a valid resistance");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorClassCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'armor class' element for this type of object.\n";

    string err = catch (Item->set("armor class", 10));
    ExpectEq(expected, err, "armor class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void DefenseClassCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'defense class' element for this type of object.\n";

    string err = catch (Item->set("defense class", 10));
    ExpectEq(expected, err, "defense class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponClassCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'weapon class' element for this type of object.\n";

    string err = catch (Item->set("weapon class", 10));
    ExpectEq(expected, err, "weapon class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void HitMethodCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'hit method' element for this type of object.\n";

    string err = catch (Item->set("hit method", "blah"));
    ExpectEq(expected, err, "hit method cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorTypeCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'armor type' element for this type of object.\n";

    string err = catch (Item->set("armor type", "blah"));
    ExpectEq(expected, err, "armor type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponTypeCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'weapon type' element for this type of object.\n";

    string err = catch (Item->set("weapon type", "blah"));
    ExpectEq(expected, err, "weapon type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'offhand' element for this type of object.\n";

    string err = catch (Item->set("offhand", "blah"));
    ExpectEq(expected, err, "offhand cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CursedCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'cursed' element for this type of object.\n";

    string err = catch (Item->set("cursed", 1));
    ExpectEq(expected, err, "cursed cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void PrerequisitesCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'prerequisites' element for this type of object.\n";

    string err = catch (Item->set("prerequisites", "blah"));
    ExpectEq(expected, err, "prerequisites cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void EquipMessageCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'equip message' element for this type of object.\n";

    string err = catch (Item->set("equip message", "blah"));
    ExpectEq(expected, err, "equip message cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void EquipMethodCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'equip method' element for this type of object.\n";

    string err = catch (Item->set("equip method", "blah"));
    ExpectEq(expected, err, "equip method cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipMessageCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'unequip message' element for this type of object.\n";

    string err = catch (Item->set("unequip message", "blah"));
    ExpectEq(expected, err, "unequip message cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void EquipmentLocationsCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'equipment locations' element for this type of object.\n";

    string err = catch (Item->set("equipment locations", "blah"));
    ExpectEq(expected, err, "equipment locations cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipMethodCannotBeSet()
{
    string expected = "*Item: It is illegal to set the 'unequip method' element for this type of object.\n";

    string err = catch (Item->set("unequip method", "blah"));
    ExpectEq(expected, err, "unequip method cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CustomKeysCanBeSet()
{
    ExpectTrue(Item->set("llama", 10), "Can set a custom key");
    ExpectEq(10, Item->query("llama"), "Custom keys return the correct value");
}

/////////////////////////////////////////////////////////////////////////////
void ShortReturnsCorrectMessage()
{
    Item->set("short", "a Statue of a Weasel");

    object owner = clone_object("/lib/modules/materialAttributes");
    owner->Name("Harold");
    owner->Gender(1);
    move_object(Item, owner);
    ExpectEq("A Statue of a Weasel", Item->short(), "short() returns correct value");

    Item->set("short", "##UserPossessive## Statue of a Weasel");
    ExpectEq("Your Statue of a Weasel", Item->short(), "short() returns correct possessive value");
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsCorrectMessageBeforeIdentification()
{
    Item->set("long", "Blah blah blah");
    Item->set("additional long", "even more blah");

    ExpectEq("Blah blah blah\n[0;37;1mThis item is typical for its type.\n[0m[0;36mThis item has not been identified.\n[0m\n", Item->long(), "long() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void LongReturnsCorrectMessageAfterIdentification()
{
    Item->set("long", "Blah blah blah");
    Item->set("additional long", "even more blah");

    ExpectTrue(Item->identify());
    ExpectEq("Blah blah blah even more blah\n[0;37;1mThis item is typical for its type.\n[0m\n", Item->long(), "long() returns correct value after ID");
}

/////////////////////////////////////////////////////////////////////////////
void ReadReturnsCorrectMessageBeforeIdentification()
{
    Item->set("name", "blah");
    Item->set("read message unidentified", "A mysterious thingy");
    Item->set("read message identified", "A watery manifestation of a vengeful, wrathful god");

    ExpectEq("A mysterious thingy", Item->readMessage("blah"), "readMessage() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void ReadReturnsCorrectMessageAfterIdentification()
{
    Item->set("name", "blah");
    Item->set("read message unidentified", "A mysterious thingy");
    Item->set("read message identified", "A watery manifestation of a vengeful, wrathful god");

    Item->identify();
    ExpectEq("A watery manifestation of a vengeful, wrathful god", Item->readMessage("blah"), "readMessage() returns correct value");
}

/////////////////////////////////////////////////////////////////////////////
void ReadReturnsEmptyIfPassedStringNotItemId()
{
    Item->set("name", "blah");
    Item->set("aliases", ({ "thingy" }));
    Item->set("read message unidentified", "A mysterious thingy");

    ExpectTrue(Item->read("blah"), "read() returns true if id is name");
    ExpectTrue(Item->read("thingy"), "read() returns true if id is alias");
    ExpectFalse(Item->read("blarg"), "read() returns false if id is unknown");
}

/////////////////////////////////////////////////////////////////////////////
void IdentificationOnlyHappensOnce()
{
    ExpectTrue(Item->identify());
    ExpectFalse(Item->identify());
}

/////////////////////////////////////////////////////////////////////////////
void IdReturnsTrueForCorrectIdentifiers()
{
    // This test is kinda dumb - but long prints to stdout
    Item->set("name", "Gertrude");
    Item->set("aliases", ({ "creature", "weasel", "Gerty" }));

    ExpectTrue(Item->id("Gertrude"), "Gertrude is a valid id");
    ExpectTrue(Item->id("creature"), "creature is a valid id");
    ExpectTrue(Item->id("weasel"), "weasel is a valid id");
    ExpectTrue(Item->id("Gerty"), "Gerty is a valid id");
    ExpectFalse(Item->id("George"), "George is not a valid id");
}

