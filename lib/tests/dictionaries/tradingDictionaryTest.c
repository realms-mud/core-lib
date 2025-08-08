//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;
object MockPort;
object MockTrader;
object MockPlayer;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "__inline_lib_tests_dictionaries_tradingDictionaryTest_c_231_#0000"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = clone_object("/lib/dictionaries/tradingDictionary.c");
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockTrader = clone_object("/lib/tests/support/services/mockPlayer.c");
    MockPlayer = clone_object("/lib/tests/support/services/mockPlayer.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Dictionary)) destruct(Dictionary);
    if (objectp(MockPort)) destruct(MockPort);
    if (objectp(MockTrader)) destruct(MockTrader);
    if (objectp(MockPlayer)) destruct(MockPlayer);
}

/////////////////////////////////////////////////////////////////////////////
void RegisterPortAndGetPort()
{
    int initialPorts = sizeof(Dictionary.getAvailablePorts());

    Dictionary.registerPort(MockPort);
    object *ports = Dictionary.getAvailablePorts();
    ExpectTrue(sizeof(ports) == initialPorts + 1, "Port registered successfully");
    ExpectEq(MockPort, ports[0], "Registered port is returned by getAvailablePorts");

    object port = Dictionary.getPort(MockPort.getPortName());
    ExpectEq(MockPort, port, "getPort returns the registered port");
}

/////////////////////////////////////////////////////////////////////////////
void RegisterPortRejectsInvalidPort()
{
    object notAPort = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    string error = catch(Dictionary.registerPort(notAPort); nolog);
    ExpectTrue(stringp(error) && sizeof(error), "registerPort raises error for invalid port");
    destruct(notAPort);
}

/////////////////////////////////////////////////////////////////////////////
void GetPortRaisesErrorForUnknownPort()
{
    string error = catch(Dictionary.getPort("Nonexistent Port"); nolog);
    ExpectTrue(stringp(error) && sizeof(error), "getPort raises error for unknown port");
}

/////////////////////////////////////////////////////////////////////////////
void GetAvailablePortsRemovesInvalidObjects()
{
    Dictionary.registerPort(MockPort);

    object *ports = Dictionary.getAvailablePorts();
    int numberOfPorts = sizeof(ports);
    ExpectTrue(numberOfPorts > 1, "getAvailablePorts returns valid ports");

    // Simulate port being destructed
    destruct(MockPort);
    
    ports = Dictionary.getAvailablePorts();
    ExpectEq(numberOfPorts - 1, sizeof(ports), 
        "getAvailablePorts removes destructed ports");
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingTypesReturnsAllTypes()
{
    string *types = Dictionary.getTradingTypes();
    ExpectTrue(pointerp(types) && sizeof(types), "getTradingTypes returns a non-empty array");
    // Spot check for some expected types
    ExpectTrue(member(types, "metal") > -1, "metal is a trading type");
    ExpectTrue(member(types, "food") > -1, "food is a trading type");
    ExpectTrue(member(types, "spices") > -1, "spices is a trading type");
}

/////////////////////////////////////////////////////////////////////////////
void GetItemListForTypeReturnsItems()
{
    string *types = Dictionary.getTradingTypes();
    foreach(string type in types)
    {
        string *items = Dictionary.getItemListForType(type);
        ExpectTrue(pointerp(items), sprintf("getItemListForType returns an array for type %s", type));
        // It's possible for some types to be empty if directories are empty, so just check for array
    }
}

/////////////////////////////////////////////////////////////////////////////
void GetAllTradingItemsReturnsFlatList()
{
    string *allItems = Dictionary.getAllTradingItems();
    ExpectTrue(pointerp(allItems), "getAllTradingItems returns an array");
    // Should contain at least some items if directories/files exist
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingHelpDisplayReturnsString()
{
    MockPlayer.Name("testtrader");
    string display = Dictionary.getTradingHelpDisplay(MockPlayer);
    ExpectTrue(stringp(display), "getTradingHelpDisplay returns a string");
    ExpectTrue(sizeof(regexp(({ display }), ".*Trading Commands.*")), "Display contains Trading Commands");
}

/////////////////////////////////////////////////////////////////////////////
void GetMarketPricesDisplayReturnsString()
{
    MockPlayer.Name("testtrader");
    Dictionary.registerPort(MockPort);
    string display = Dictionary.getMarketPricesDisplay(MockPlayer, MockPort);
    ExpectTrue(stringp(display), "getMarketPricesDisplay returns a string");
    ExpectTrue(sizeof(regexp(({ display }), ".*Market Prices.*")), "Display contains Market Prices");
}

/////////////////////////////////////////////////////////////////////////////
void GetAvailableGoodsReturnsMapping()
{
    Dictionary.registerPort(MockPort);
    mapping goods = Dictionary.getAvailableGoods(MockPort, MockTrader);
    ExpectTrue(mappingp(goods), "getAvailableGoods returns a mapping");
}

/////////////////////////////////////////////////////////////////////////////
void GetCargoForSaleReturnsMapping()
{
    Dictionary.registerPort(MockPort);
    mapping cargo = Dictionary.getCargoForSale(MockTrader, MockPort);
    ExpectTrue(mappingp(cargo), "getCargoForSale returns a mapping");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateWarehouseUsedReturnsSum()
{
    mapping warehouse = ([ "inventory": ([ "/lib/instances/items/food/bread/wheat-bread": 5, "/lib/instances/items/materials/metal/iron": 3 ]) ]);
    int used = Dictionary.calculateWarehouseUsed(warehouse);
    ExpectEq(8, used, "calculateWarehouseUsed returns correct sum");
}

/////////////////////////////////////////////////////////////////////////////
void FormatTradingMessageReturnsDecoratedString()
{
    MockPlayer.Name("testtrader");
    string msg = Dictionary.formatTradingMessage("Success!", "success", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Dictionary.formatTradingMessage("Failure!", "failure", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Dictionary.formatTradingMessage("Warning!", "warning", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Dictionary.formatTradingMessage("Info!", "info", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidTradeItemReturnsCorrectly()
{
    string *allItems = Dictionary.getAllTradingItems();
    if (sizeof(allItems))
    {
        ExpectTrue(Dictionary.isValidTradeItem(allItems[0]), "isValidTradeItem returns true for valid item");
    }
    int result = Dictionary.isValidTradeItem("/lib/instances/items/food/imaginary-item");
    ExpectFalse(result, "isValidTradeItem returns false for invalid item");
}


/////////////////////////////////////////////////////////////////////////////
void GetTradeRouteTypesReturnsMapping()
{
    mapping routes = Dictionary.getTradeRouteTypes();
    ExpectTrue(mappingp(routes), "getTradeRouteTypes returns a mapping");
    ExpectTrue(member(routes, "maritime") > -1, "maritime route exists");
    ExpectTrue(member(routes, "overland") > -1, "overland route exists");
    ExpectTrue(member(routes, "river") > -1, "river route exists");
}

/////////////////////////////////////////////////////////////////////////////
void ValidSingleItemReturnsTrue()
{
    string *allItems = Dictionary->getAllTradingItems();
    string validItem = sizeof(allItems) ? allItems[0] : "/lib/instances/items/materials/metal/iron.c";
    ExpectTrue(Dictionary->isValidTradingItem(validItem), "A valid single item string should return true");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSingleItemReturnsFalse()
{
    string invalidItem = "/lib/instances/items/materials/metal/not-a-real-item.c";
    ExpectFalse(Dictionary->isValidTradingItem(invalidItem), "An invalid single item string should return false");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfThreeValidItemsReturnsTrue()
{
    string *allItems = Dictionary->getAllTradingItems();
    string *validItems = allItems[0..2];
    ExpectTrue(Dictionary->isValidTradingItem(validItems), "An array of three valid items should return true");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayWithInvalidItemReturnsFalse()
{
    string *allItems = Dictionary->getAllTradingItems();
    string *items = ({ allItems[0], allItems[1], "/lib/instances/items/materials/metal/not-a-real-item.c" });
    ExpectFalse(Dictionary->isValidTradingItem(items), "An array with an invalid item should return false");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfObjectsReturnsTrueIfAllValid()
{
    string *allItems = Dictionary->getAllTradingItems();
    object *objects = map(allItems[0..2], (: load_object($1) :));
    ExpectTrue(Dictionary->isValidTradingItem(objects), "An array of valid item objects should return true");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfObjectsReturnsFalseIfAnyInvalid()
{
    string *allItems = Dictionary->getAllTradingItems();
    object *objects = ({ load_object(allItems[0]), load_object(allItems[1]), clone_object("/lib/core/thing.c") });
    ExpectFalse(Dictionary->isValidTradingItem(objects), "An array with an invalid object should return false");
}
