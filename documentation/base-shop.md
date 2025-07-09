#### Dissecting a Shop
In this section, I'll describe how to create a shop by using 
/lib/environment/shopInventories/armorer.c as an example.

Let's look at the file and go through it line by line:

~~~c
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Armorer");
    welcomeMessage("Welcome to the armorer's shop");
    shopType("armor");
    shopSubType("heavy armor");
}
~~~

This sets up your shop object to inherit/use all of the goodies that make 
it a shop. Note that shops inherit from baseShop.c, not from baseTerrain.c 
like terrain objects do.

We've given your shop a name with `name("The Armorer")`. This is the name 
that will be displayed to players when they interact with the shop.

The `welcomeMessage("Welcome to the armorer's shop")` method sets the 
greeting message that players see when they enter the shop interface.

The `shopType("armor")` method defines what category of items this shop 
sells. Valid types include "armor", "weapons", "instruments", "potions", 
"herbs", "drinks", "books", "metal", "gems", and others.

The `shopSubType("heavy armor")` method narrows down the specific 
subcategory of items. For armor shops, this could be "heavy armor", 
"light armor", "medium armor", "clothing", or "accessories". Use "all" if 
you want the shop to sell all subtypes of the main type.

##### Environmental Element Features
For all of the base environmental element features that shops inherit 
(descriptions, adjectives, time of day descriptions, season descriptions, 
lighting, harvestable resources, environmental bonuses, environmental 
limitors, state machines, etc.), please refer to [terrain.md](terrain.md). 

Shops inherit from environmentalElement.c through the same system as 
terrains, so **all** of those features apply to shops as well. This means 
your shops can have dynamic descriptions that change with time and season, 
provide environmental bonuses to players, offer harvestable resources, 
have complex lighting systems, and use state machines for quest 
integration - just like any terrain object.

##### Shop-Specific Features

##### Inventory Management
Shops have sophisticated inventory management systems that handle both 
specified items and randomly generated inventory.

###### Random Inventory Generation
By default, shops will generate random items based on their type and 
subtype. The `setRandomItemsToGenerate(int numberOfItems)` method controls 
how many random items are generated when the inventory is updated. The 
default is 15 items.

~~~c
setRandomItemsToGenerate(20); // Generate 20 random items
~~~

###### Specified Inventory Items
You can specify exact items that should always be available in the shop. 
The `addInventoryItem(string type, string subType, string *items)` method 
allows you to specify exactly which items should be available. These work 
alongside the randomly generated items.

~~~c
addInventoryItem("weapons", "swords", ({ "long-sword", "bastard-sword", 
    "claymore" }));
addInventoryItem("armor", "heavy armor", ({ "plate-armor", "chainmail" }));
~~~

###### Individual Custom Items
You can add specific item files that should always be in stock. The 
`addItem(string fileName)` method adds a specific item file to the shop's 
permanent inventory. The item file must inherit from "/lib/items/item.c".

~~~c
addItem("/lib/domains/town/obj/special-sword.c");
addItem("/lib/domains/castle/obj/royal-armor.c");
~~~

##### Shop Types and Behavior

###### Equipment Shops
Equipment shops (armor, weapons, instruments) have special behavior:
- They generate items with random materials and craftsmanship
- They maintain a mix of quality levels
- They have default items that are always available
- Players can sell equipment back to these shops

~~~c
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Weaponsmith");
    welcomeMessage("Welcome to the finest weapons shop in the realm!");
    shopType("weapons");
    shopSubType("swords");
    setRandomItemsToGenerate(25);
    
    // Always stock these basic weapons
    addInventoryItem("weapons", "swords", ({ 
        "dagger", "short-sword", "long-sword", "bastard-sword" 
    }));
    
    // Special masterwork item
    addItem("/lib/domains/town/obj/masterwork-blade.c");
}
~~~

###### Consumable Shops
Consumable shops (potions, herbs, books, materials) work differently:
- They generate items with quantities
- They have permanent items that never run out
- They refresh their random stock regularly

~~~c
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Alchemist");
    welcomeMessage("Potions and elixirs for all your needs!");
    shopType("potions");
    shopSubType("all");
    
    // This will generate consumable items with quantities
}
~~~

##### Shop Interaction System
The shop system provides a complete menu-driven interface for players:

1. **Main Shop Menu**: Buy items, sell items, or exit
2. **Buy Interface**: Browse items by category with detailed descriptions
3. **Sell Interface**: Sell items from inventory with value calculations

##### Inventory Updates
Shop inventories are automatically managed. The `updateShopInventory()` 
method is called automatically during resets and performs these functions:

1. Removes non-permanent items that were sold
2. Generates new random items if inventory is low
3. Updates custom items to ensure they're in stock
4. Maintains permanent items

~~~c
updateShopInventory(); // Called automatically during resets
~~~

##### Advanced Shop Features

###### Permanent vs. Temporary Items
Items in shops can be marked as permanent or temporary:
- **Permanent items**: Never run out, always restocked
- **Temporary items**: Removed when sold, replaced during inventory updates
- **Custom items**: Added via `addItem()`, always restocked when missing

###### Shop Events
Shops automatically handle interaction events through the shop selector 
system. The system manages the complete buying and selling interface 
without requiring additional code in most cases.

##### Complete Shop Example
Here's a complete shop implementation showing all the available features:

~~~c
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("Mystical Emporium");
    welcomeMessage("Welcome to the Mystical Emporium, where magic meets "
        "commerce!");
    shopType("weapons");
    shopSubType("all");
    setRandomItemsToGenerate(30);
    
    // Basic terrain features (see terrain.md for details)
    addDescriptionTemplate("a mystical shop filled with ##Adjective##");
    addAdjectives(({ 
        "gleaming weapons and shimmering armor",
        "mysterious artifacts and ancient relics",
        "magical implements and enchanted gear"
    }));
    
    // Lighting
    addSourceOfLight(8); // Well-lit shop
    
    // Shop-specific inventory
    addInventoryItem("weapons", "swords", ({ "long-sword", 
        "bastard-sword" }));
    addInventoryItem("weapons", "staffs", ({ "quarterstaff", "staff" }));
    addInventoryItem("armor", "light armor", ({ "leather-jacket", 
        "soft-leather" }));
    
    // Special items
    addItem("/lib/domains/town/obj/enchanted-blade.c");
    addItem("/lib/domains/town/obj/crystal-armor.c");
    
    // Environmental bonuses for shopping
    addBonus("barter", 2); // Easier to negotiate prices
}
~~~

##### Integration with Environments
Shops are typically added to environments using the `addShop(string shop)` 
method in environment files:

~~~c
// In an environment file
public void Setup()
{
    setShort("a bustling marketplace");
    addShop("/lib/domains/town/shops/armorer.c");
    addShop("/lib/domains/town/shops/weaponsmith.c");
}
~~~

This creates interactive shop objects that players can use with commands 
like:
- `list` - Browse shop inventory
- `buy <item>` - Purchase an item
- `sell <item>` - Sell an item to the shop
- `value <item>` - Check item's sell value

The shop system integrates seamlessly with the game's economy, skill system 
(barter, persuasion, etc.), and item identification mechanics to provide a 
rich commercial experience for players.
