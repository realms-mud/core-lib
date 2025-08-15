//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
object MockPort;
object MockTrader;
object MockPlayer;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "__inline_lib_tests_services_tradingServiceTest_c_224_#0000"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/tradingService.c");
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockPort.setPortName("Mock Trading Port");

    MockTrader = clone_object("/lib/tests/support/services/mockPlayer.c");
    MockPlayer = clone_object("/lib/tests/support/services/mockPlayer.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Service)) destruct(Service);
    if (objectp(MockPort)) destruct(MockPort);
    if (objectp(MockTrader)) destruct(MockTrader);
    if (objectp(MockPlayer)) destruct(MockPlayer);
}

/////////////////////////////////////////////////////////////////////////////
void RegisterPortAndGetPort()
{
    int initialPorts = sizeof(Service.getAvailablePorts());

    Service.registerPort(MockPort);
    object *ports = Service.getAvailablePorts();

    ExpectTrue(sizeof(ports) == initialPorts + 1, "Port registered successfully");
    ExpectEq(MockPort, ports[0], "Registered port is returned by getAvailablePorts");

    object port = Service.getPort(MockPort.getPortName());
    ExpectEq(MockPort, port, "getPort returns the registered port");
}

/////////////////////////////////////////////////////////////////////////////
void RegisterPortRejectsInvalidPort()
{
    object notAPort = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    string error = catch(Service.registerPort(notAPort); nolog);
    ExpectTrue(stringp(error) && sizeof(error), "registerPort raises error for invalid port");
    destruct(notAPort);
}

/////////////////////////////////////////////////////////////////////////////
void GetPortRaisesErrorForUnknownPort()
{
    string error = catch(Service.getPort("Nonexistent Port"); nolog);
    ExpectTrue(stringp(error) && sizeof(error), "getPort raises error for unknown port");
}

/////////////////////////////////////////////////////////////////////////////
void GetAvailablePortsRemovesInvalidObjects()
{
    Service.registerPort(MockPort);

    object *ports = Service.getAvailablePorts();
    int numberOfPorts = sizeof(ports);
    ExpectTrue(numberOfPorts > 1, "getAvailablePorts returns valid ports");

    // Simulate port being destructed
    destruct(MockPort);
    
    ports = Service.getAvailablePorts();
    ExpectEq(numberOfPorts - 1, sizeof(ports), 
        "getAvailablePorts removes destructed ports");
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingTypesReturnsAllTypes()
{
    string *types = Service.getTradingTypes();
    ExpectTrue(pointerp(types) && sizeof(types), "getTradingTypes returns a non-empty array");
    // Spot check for some expected types
    ExpectTrue(member(types, "metal") > -1, "metal is a trading type");
    ExpectTrue(member(types, "food") > -1, "food is a trading type");
    ExpectTrue(member(types, "spices") > -1, "spices is a trading type");
}

/////////////////////////////////////////////////////////////////////////////
void GetItemListForTypeReturnsItems()
{
    string *types = Service.getTradingTypes();
    foreach(string type in types)
    {
        string *items = Service.getItemListForType(type);
        ExpectTrue(pointerp(items), sprintf("getItemListForType returns an array for type %s", type));
        // It's possible for some types to be empty if directories are empty, so just check for array
    }
}

/////////////////////////////////////////////////////////////////////////////
void GetAllTradingItemsReturnsFlatList()
{
    string *allItems = Service.getAllTradingItems();
    ExpectTrue(pointerp(allItems), "getAllTradingItems returns an array");
    // Should contain at least some items if directories/files exist
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingHelpDisplayReturnsString()
{
    MockPlayer.Name("testtrader");
    string display = Service.getTradingHelpDisplay(MockPlayer);
    ExpectTrue(stringp(display), "getTradingHelpDisplay returns a string");
    ExpectTrue(sizeof(regexp(({ display }), ".*Trading Commands.*")), "Display contains Trading Commands");
}

/////////////////////////////////////////////////////////////////////////////
void GetAvailableGoodsReturnsMapping()
{
    Service.registerPort(MockPort);
    mapping goods = Service.getAvailableGoods(MockPort, MockTrader);
    ExpectTrue(mappingp(goods), "getAvailableGoods returns a mapping");
}

/////////////////////////////////////////////////////////////////////////////
void GetCargoForSaleReturnsMapping()
{
    Service.registerPort(MockPort);
    mapping cargo = Service.getCargoForSale(MockTrader, MockPort);
    ExpectTrue(mappingp(cargo), "getCargoForSale returns a mapping");
}

/////////////////////////////////////////////////////////////////////////////
void CalculateWarehouseUsedReturnsSum()
{
    mapping warehouse = ([ "inventory": ([ "/lib/instances/items/food/bread/wheat-bread": 5, "/lib/instances/items/materials/metal/iron": 3 ]) ]);
    int used = Service.calculateWarehouseUsed(warehouse);
    ExpectEq(8, used, "calculateWarehouseUsed returns correct sum");
}

/////////////////////////////////////////////////////////////////////////////
void FormatTradingMessageReturnsDecoratedString()
{
    MockPlayer.Name("testtrader");
    string msg = Service.formatTradingMessage("Success!", "success", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Service.formatTradingMessage("Failure!", "failure", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Service.formatTradingMessage("Warning!", "warning", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
    msg = Service.formatTradingMessage("Info!", "info", MockPlayer);
    ExpectTrue(stringp(msg), "formatTradingMessage returns a string");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidTradeItemReturnsCorrectly()
{
    string *allItems = Service.getAllTradingItems();
    if (sizeof(allItems))
    {
        ExpectTrue(Service.isValidTradeItem(allItems[0]), "isValidTradeItem returns true for valid item");
    }
    int result = Service.isValidTradeItem("/lib/instances/items/food/imaginary-item");
    ExpectFalse(result, "isValidTradeItem returns false for invalid item");
}


/////////////////////////////////////////////////////////////////////////////
void GetTradeRouteTypesReturnsMapping()
{
    mapping routes = Service.getTradeRouteTypes();
    ExpectTrue(mappingp(routes), "getTradeRouteTypes returns a mapping");
    ExpectTrue(member(routes, "maritime") > -1, "maritime route exists");
    ExpectTrue(member(routes, "overland") > -1, "overland route exists");
    ExpectTrue(member(routes, "river") > -1, "river route exists");
}

/////////////////////////////////////////////////////////////////////////////
void ValidSingleItemReturnsTrue()
{
    string *allItems = Service->getAllTradingItems();
    string validItem = sizeof(allItems) ? allItems[0] : "/lib/instances/items/materials/metal/iron.c";
    ExpectTrue(Service->isValidTradingItem(validItem), "A valid single item string should return true");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSingleItemReturnsFalse()
{
    string invalidItem = "/lib/instances/items/materials/metal/not-a-real-item.c";
    ExpectFalse(Service->isValidTradingItem(invalidItem), "An invalid single item string should return false");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfThreeValidItemsReturnsTrue()
{
    string *allItems = Service->getAllTradingItems();
    string *validItems = allItems[0..2];
    ExpectTrue(Service->isValidTradingItem(validItems), "An array of three valid items should return true");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayWithInvalidItemReturnsFalse()
{
    string *allItems = Service->getAllTradingItems();
    string *items = ({ allItems[0], allItems[1], "/lib/instances/items/materials/metal/not-a-real-item.c" });
    ExpectFalse(Service->isValidTradingItem(items), "An array with an invalid item should return false");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfObjectsReturnsTrueIfAllValid()
{
    string *allItems = Service->getAllTradingItems();
    object *objects = map(allItems[0..2], (: load_object($1) :));
    ExpectTrue(Service->isValidTradingItem(objects), "An array of valid item objects should return true");
}

/////////////////////////////////////////////////////////////////////////////
void ArrayOfObjectsReturnsFalseIfAnyInvalid()
{
    string *allItems = Service->getAllTradingItems();
    object *objects = ({ load_object(allItems[0]), load_object(allItems[1]), clone_object("/lib/core/thing.c") });
    ExpectFalse(Service->isValidTradingItem(objects), "An array with an invalid object should return false");
}
