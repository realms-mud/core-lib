## Equipment System Overview

Equipment in this MUD is a sophisticated, multi-layered system supporting 
everything from simple iron swords to complex, multi-material masterworks 
with enchantments. It integrates player crafting, monster equipment, and 
world-placed items through a unified, component-based architecture. The 
system is designed to be both flexible and powerful, allowing creators 
to define items with a high degree of customization and realism.

The equipment system operates on three fundamental levels:
1. **Blueprint System**: Defines base item types and their core characteristics.
2. **Materials System**: Determines how different materials affect item properties.
3. **Crafting System**: Allows for component-based construction and customization.

---

## 1. Equipment Inheritance and File Structure

Before you begin creating equipment, it is essential to understand the 
inheritance hierarchy and where the relevant code and data are located. 
The inheritance chain ensures that all items, weapons, and armor 
automatically gain the correct behaviors and properties, and that your 
customizations are layered on top of a robust foundation.

### Inheritance Chain

Every equipment item must inherit from one of the following base classes:

~~~c
inherit "/lib/items/equipment.c"; // For generic equipment
// OR
inherit "/lib/items/weapon.c";   // For weapons  
// OR
inherit "/lib/items/armor.c";    // For armor
~~~

- **lib/items/item.c**: Provides basic item functionality such as naming, identification, and value.
- **lib/items/equipment.c**: Adds mechanics for equipping, prerequisites, and bonuses.
- **lib/items/weapon.c**: Adds weapon-specific properties and combat behaviors.
- **lib/items/armor.c**: Adds armor-specific properties and defensive behaviors.

### System File Locations

Understanding where to find and edit the relevant files is crucial for effective item creation:

- **Core Logic**: `lib/items/item.c`, `lib/items/equipment.c`, `lib/items/weapon.c`, `lib/items/armor.c`
- **Services**: `lib/services/materialsService.c`, `lib/services/craftingService.c`
- **Blueprints**: `lib/services/materials/weapons.h`, `lib/services/materials/armor.h`
- **Components**: `lib/services/materials/components.h`, `lib/services/materials/components/*.c`
- **Materials**: `lib/services/materials/materials.h`
- **Enchantments**: `lib/services/materials/enchantments.h`
- **Crafting Logic**: `lib/services/crafting/*.c`
- **Crafting UI**: `lib/modules/crafting/*Selector.c`

---

## 2. Creating Equipment: Step-by-Step Tutorial

This section provides a comprehensive, step-by-step guide to creating new 
equipment. Whether you are making a simple item or a complex, 
multi-component masterwork, these steps will help you understand the process 
and the reasoning behind each choice.

### Step 1: Choose Your Inheritance

The first decision is what kind of item you are making. This determines 
which properties and behaviors are available to you.

- **Weapon**: If your item is a weapon (sword, axe, bow, etc.), inherit from `/lib/items/weapon.c`. This gives you access to weapon-specific properties such as damage type, weapon class, and attack speed.
- **Armor**: If your item is armor (helmet, breastplate, boots, etc.), inherit from `/lib/items/armor.c`. This provides armor-specific properties like armor class and armor type.
- **Other Equipment**: For items that are neither weapons nor armor (rings, cloaks, amulets, etc.), inherit from `/lib/items/equipment.c`. This is the most generic form and is suitable for accessories and utility items.

Choosing the correct inheritance ensures your item interacts properly 
with the game’s systems, such as combat, inventory, and character progression.

### Step 2: Set the Blueprint

A blueprint is the foundation of your item. It defines the base 
type, default stats, crafting requirements, and component structure. 
Blueprints are stored in files like `lib/services/materials/weapons.h` and 
`lib/services/materials/armor.h`, and are referenced by name.

For example, to create a long sword, you would set:

~~~c
set("blueprint", "long sword");
~~~

#### What does this do?

Setting the blueprint to `"long sword"` automatically applies all 
the default values and requirements defined in the `weaponBlueprints`
mapping for `"long sword"` in `weapons.h`. Here is the actual mapping:

~~~c
"long sword": ([
    "type": "weapon",
    "subtype": "sword",
    "default location": OnehandedWeapon,
    "damage type": "slash",
    "skill to craft": 10,
    "crafting prerequisites": ([
        "/lib/instances/research/crafting/weapons/swords/craftLongSwords.c":(["type":"research"]),
        "blacksmithing": (["type":"skill", "value": 1]),
        "metal crafting": (["type":"skill", "value": 1]),
        "weapon smithing": (["type":"skill", "value": 8]),
    ]),
    "primary component": "blade", 
    "crafting materials": ([
        "blade": (["metal": 6 ]),
        "crossguard": (["metal": 2, "crystal": 0 ]),
        "hilt": (["metal": 1, "wood": 1, "leather": 1 ]),
        "pommel": (["metal": 1, "crystal": 0 ]),
    ]),
    "skill to use": "long sword",
    "default wc": 10,
    "default dc": 2,
    "default attack": 5,
    "default weight": 5,
    "default encumberance": 5,
    "default material": "iron",
    "default value": 200,
    "default description": "This is a sword with a blade that is about 40 inches (100 cm) long.",
    "base experience": 10,
]),
~~~

#### Breakdown of Blueprint Values

When you set `"blueprint": "long sword"`, the following properties are automatically set on your weapon (unless you override them with your own `set` calls):

- **type**: `"weapon"` – The item is classified as a weapon.
- **subtype**: `"sword"` – The weapon subtype.
- **default location**: `OnehandedWeapon` – The inventory slot where the item is equipped.
- **damage type**: `"slash"` – The type of damage this weapon deals.
- **skill to craft**: `10` – The minimum skill required to craft this item.
- **crafting prerequisites**: Mapping of required research and skills to craft the item.
- **primary component**: `"blade"` – The main component for stat calculations.
- **crafting materials**: Mapping of required materials for each component (blade, crossguard, hilt, pommel).
- **skill to use**: `"long sword"` – The skill used to wield the weapon.
- **default wc**: `10` – The base weapon class (damage potential).
- **default dc**: `2` – The base defense class (defensive bonus).
- **default attack**: `5` – The base attack rating (speed/accuracy).
- **default weight**: `5` – The base weight of the item.
- **default encumberance**: `5` – The base encumbrance value.
- **default material**: `"iron"` – The default material for the weapon.
- **default value**: `200` – The base monetary value.
- **default description**: `"This is a sword with a blade that is about 40 inches (100 cm) long."` – The default long description.
- **base experience**: `10` – The base experience granted for crafting.

#### Overriding Blueprint Values

You can override any of these defaults by explicitly setting 
the property with the `set` method in your item's `Setup()` function. 
For example:

~~~c
set("material", "steel");           // Overrides default material "iron"
set("weapon class", 12);            // Overrides default wc 10
set("defense class", 4);            // Overrides default dc 2
set("value", 500);                  // Overrides default value 200
set("long", "A legendary sword with a shimmering blade."); // Custom description
~~~

This allows you to use the blueprint as a starting point, but 
customize the item to fit your needs, whether you want to make a
masterwork, magical, or unique variant.

#### Why Use Blueprints?

- **Consistency**: Ensures all items of a given type start with the same stats and requirements.
- **Efficiency**: Reduces the amount of manual setup needed for standard items.
- **Extensibility**: You can create new blueprints for new item types, or override any value for custom items.
- **Integration**: All blueprint values are used by the crafting, combat, and inventory systems, so your item will work seamlessly with the rest of the game.

**Pro Tip:** Explore `lib/services/materials/weapons.h` and 
`lib/services/materials/armor.h` for a full list of available 
blueprints and their properties. This is the best way to discover
new item types and understand what defaults you can leverage or 
override.

### Step 3: Define Materials and Components

Materials and components are the heart of the equipment system’s flexibility. 
They allow you to specify exactly what your item is made of and how it is 
constructed, and they have a direct impact on the item's stats, value, 
and even who can craft it.

**Simple items:**  
If your item is straightforward, you can just set the material:

~~~c
set("material", "steel");
~~~

When you set the material to `"steel"`, your item will inherit all the 
properties defined for steel in `materials.h`. Here’s what the steel mapping looks like:

~~~c
"steel": ([
    "class": "metal",
    "crafting skill required": 15,   
    "crafting prerequisites": ([
        "/lib/instances/research/crafting/materials/craftAlloy.c":(["type":"research"]),
        "blacksmithing": (["type":"skill", "value": 10]),
        "metal crafting": (["type":"skill", "value": 3]),
        "chemistry": (["type":"skill", "value": 1]),
        "physics": (["type":"skill", "value": 1])
    ]),
    "crafting materials": ([
        "iron": 5,
        "graphite": 1
    ]),
    "attack": ([ "physical": 1 ]),
    "attack rating": 1,
    "defense": ([ "physical": 1 ]),
    "value multiplier": 1.1,
    "default description": "This is an iron-graphite steel ingot.",
    "scarcity": "common",
    "experience modifier": 1.2,
    "default value": 3,
]),
~~~

**What does this mean for your item?**
- **Crafting Requirements:** To craft a steel item, a player must have at least 15 in the relevant crafting skill, and meet prerequisites in blacksmithing, metal crafting, chemistry, and physics, as well as complete the `craftAlloy` research. This makes steel a step up from basic materials like iron.
- **Component Materials:** Steel is made from 5 iron and 1 graphite, so crafting steel items requires gathering and combining these resources.
- **Stat Bonuses:** Steel provides a physical attack bonus (`"attack": ([ "physical": 1 ])`), an attack rating bonus (`"attack rating": 1`), and a physical defense bonus (`"defense": ([ "physical": 1 ])`). For weapons, this means increased damage and accuracy; for armor, it means better protection.
- **Value:** The `"value multiplier": 1.1` means steel items are worth more than their iron counterparts, and `"experience modifier": 1.2` means crafting with steel grants more experience.
- **Description:** The default description and value are also set, but you can override these as needed.

**Encouragement:**  
The `materials.h` file contains many more materials, each with unique 
properties, crafting requirements, and bonuses. For example, you might find 
rare magical metals, enchanted woods, or even materials that grant elemental 
resistances or special effects. Always check `materials.h` for inspiration and 
to ensure you’re using the right material for your item’s theme and intended 
power level.

**Example of a Magical Material:**  
Suppose you want to use a magical material like `"mithril"` (see `materials.h` for the full mapping):

~~~c
"mithril": ([
    "class": "metal",
    "crafting skill required": 25,
    "crafting prerequisites": ([ ... ]),
    "attack": ([ "physical": 2, "magical": 1 ]),
    "defense": ([ "physical": 2, "magical": 1 ]),
    "value multiplier": 5.0,
    "enchantable": 1,
    "scarcity": "rare",
    ...
])
~~~

Mithril is much harder to craft, requires higher skills, and provides 
both physical and magical bonuses. It is also enchantable, making it ideal 
for legendary weapons and armor.

**Summary:**  
Setting the material is not just cosmetic—it determines the item's stats,
value, crafting requirements, and even who can make or use it. For advanced 
items, you can mix and match materials for each component using the 
`crafting materials` mapping, giving you fine-grained control over every 
aspect of your creation.

**Pro Tip:**  
Explore `lib/services/materials/materials.h` for a full list of available 
materials, their properties, and crafting requirements. This is the best 
way to discover new possibilities and ensure your items are balanced and 
interesting.

### Step 4: Set Core Properties

Core properties define the basic identity and value of your 
item. These are the first things players will notice.

~~~c
set("name", "Dragonslayer Blade");
set("short", "a masterwork dragonslayer blade");
set("aliases", ({ "blade", "sword", "dragonslayer" }));
set("long", "A masterwork blade with ornate features...");
set("value", 5000);
set("weight", 8);
set("craftsmanship", 85);
~~~

- **name**: The primary name of the item.
- **short**: The brief description shown in inventories.
- **aliases**: Alternative names for referencing the item in commands.
- **long**: The detailed description shown when the item is examined.
- **value**: The monetary value of the item.
- **weight**: The physical weight, which affects encumbrance.
- **craftsmanship**: The quality level (1-100+), which can affect stats and value.

**Tip:** Use `aliases` to make your item easier to reference 
in commands. A well-written `long` description adds flavor and immersion.

### Step 5: Add Equipment-Specific Properties

Depending on your item’s type, you can set additional properties 
to define its behavior in combat and other systems.

Below is a detailed description of every property you can set on 
equipment, including type, usage, and notes. Use this as a checklist 
and reference when designing your items.

### Naming and Description Properties

- **name**: (string) The item's primary name. Used for identification and display.
- **short**: (string) Short description shown in inventories.
- **aliases**: (array of strings) Alternative names for referencing the item.
- **long**: (string) Detailed description shown when examined.
- **additional long**: (string) Extra info shown when identified.
- **user description**: (string) Description shown when someone looks at the user when wielding/equipping the item.

### Core Item Attributes

- **value**: (int) Monetary value of the item.
- **weight**: (int) Physical weight, affects encumbrance.
- **material**: (string) Main material, affects stats and description.
- **craftsmanship**: (int) Quality level (1-100+), affects value and effectiveness.
- **charges**: (int) Number of uses for limited-use items.
- **light**: (int) Amount of light the item emits.
- **register event handler**: (int) If set, item registers for special events.
- **no steal**: (int) If set, item cannot be stolen.
- **no sell**: (int) If set, item cannot be sold.
- **owner**: (string) Name of the item's owner.
- **undroppable**: (int) If set, item cannot be dropped.
- **ungettable**: (int) If set, item cannot be picked up.

### Equipment-Specific Properties

- **blueprint**: (string) Links item to a blueprint, providing base stats and structure.
- **equipment locations**: (int/bitfield) Where the item can be equipped (see inventory.h).
- **prerequisites**: (mapping) Requirements to equip (level, skills, guilds, research, race, quests).
- **equip message**: (string) Message shown when item is equipped.
- **unequip message**: (string) Message shown when item is unequipped.
- **equip method**: (string/function) Calls a function on equip.
- **unequip method**: (string/function) Calls a function on unequip.
- **cursed**: (mapping) Cursed item messages and behavior.
- **crafting materials**: (mapping) Detailed component/material mapping.
- **primary component**: (string) Main component for stat calculations.

### Weapon-Specific Properties

- **weapon class**: (int) Damage potential.
- **defense class**: (int) Defensive bonus when wielded.
- **weapon attack**: (int) Attack speed/accuracy bonus.
- **weapon type**: (string) Skill category (e.g., "long sword").
- **damage type**: (string) Primary damage type (e.g., "slash", "thrust").
- **primary damage type**: (string) Used for magical weapons.
- **hit method**: (string/function) Calls a function on hit.
- **offhand**: (int) If set, item can be wielded in the offhand.

### Armor-Specific Properties

- **armor class**: (int) Protection value.
- **armor type**: (string) Armor category (e.g., "plate", "leather").

### Bonuses and Magical Effects

- **bonus <stat/skill>**: (int) Stat or skill bonus. Use any valid stat or skill name.
- **enchantments**: (mapping) Damage type bonuses (e.g., fire, cold, magical).
- **resistances**: (mapping) Damage resistances (e.g., fire, cold, physical).

### Component/Material System

- **crafting materials**: (mapping) Each component (blade, crossguard, hilt, pommel, etc.) can specify:
  - `description`: (string) Description of the component.
  - `<material>`: (string) Material type and name (e.g., `metal`, `wood`, `leather`, `crystal`).
  - `type`: (string) Component style/form.
  - `value`: (int) Extra value from this component.

### Equipment Location Constants

- **OnehandedWeapon**: Primary weapon slot
- **TwohandedWeapon**: Two-handed weapon slot
- **Shield**: Shield/offhand slot
- **Helmet**: Head protection
- **Armor**: Body armor
- **Gloves**: Hand protection
- **Boots**: Foot protection
- **Cloak**: Outer garment
- **Ring**, **Ring2**: Finger jewelry slots

### Example Property Definitions

**Weapons:**

~~~c
set("weapon class", 3);         // Damage potential
set("defense class", 2);        // Defensive bonus
set("weapon attack", 5);        // Attack speed/accuracy
set("weapon type", "long sword");
set("damage type", "slash");
~~~

- **weapon class**: The base damage potential of the weapon.
- **defense class**: The defensive bonus when wielded.
- **weapon attack**: The attack speed or accuracy bonus.
- **weapon type**: The skill category required to use the weapon.
- **damage type**: The primary damage type (e.g., slash, thrust, bludgeon).

**Armor:**

~~~c
set("armor class", 7);          // Protection value
set("armor type", "plate");
~~~

- **armor class**: The base protection value.
- **armor type**: The category of armor (e.g., plate, leather, chain).

**Note:** These properties override or supplement blueprint 
defaults, allowing you to fine-tune your item’s performance.

### Step 6: Add Bonuses, Enchantments, and Resistances

Bonuses, enchantments, and resistances make your items more desirable and unique.

**Stat and skill bonuses:**

~~~c
set("bonus strength", 2);
set("bonus long sword", 4);
set("bonus hit points", 25);
set("bonus armor class", 3);
~~~

- **bonus <stat/skill>**: Any valid stat or skill can be given 
- a bonus. This directly increases the player’s abilities when 
- the item is equipped.

**Enchantments:**

~~~c
set("enchantments", ([
    "fire": 15,
    "magical": 5
]));
~~~

- **enchantments**: Adds magical damage types to attacks. 
- Each key is a damage type, and the value is the bonus amount.

**Resistances:**

~~~c
set("resistances", ([
    "fire": 20,
    "cold": 15,
    "physical": 10
]));
~~~

- **resistances**: Reduces incoming damage of specific types. 
- Each key is a damage type, and the value is the percentage 
- reduction.

**Tip:** Use bonuses and enchantments to create legendary 
items, quest rewards, or rare drops that players will strive to obtain.

### Step 7: Set Prerequisites and Restrictions

Prerequisites control who can use your item, adding depth and
progression to the game.

~~~c
set("prerequisites", ([
    "level": 15,
    "skills": ([ "long sword": 10 ]),
    "guilds": ([ "allowed": ({ "fighter", "paladin" }) ]),
    "research": ([ "advanced swordplay": 1 ]),
    "race": "elf"
]));
~~~

- **level**: Minimum character level required.
- **skills**: Minimum skill levels required.
- **guilds**: Restricts item to certain guilds.
- **research**: Requires completion of specific research.
- **race**: Restricts item to a specific race.

**Tip:** Use prerequisites to gate powerful items behind progression, 
achievements, or story events.

### Step 8: Set Equipment Location

Specify where the item can be equipped using bitfield constants. This 
determines which inventory slot the item occupies.

~~~c
set("equipment locations", OnehandedWeapon);
~~~

Other options include: `TwohandedWeapon`, `Shield`, `Helmet`, `Armor`, `Gloves`, `Boots`, `Cloak`, `Ring`, `Ring2`.

**Tip:** Properly setting equipment locations ensures your item 
interacts correctly with the character’s inventory and equipment system.

### Step 9: Add Special Properties

Special properties allow you to create items with unique behaviors and restrictions.

**Cursed items:**

~~~c
set("cursed", ([
    "equip message": "The sword adheres to your hand!",
    "failed unequip message": "The cursed blade will not release you!"
]));
~~~

- **cursed**: Prevents the item from being unequipped, with custom messages.

**Other properties:**

~~~c
set("charges", 50);                // Limited use items
set("light", 5);                   // Light source
set("register event handler", 1);  // Special event processing
set("owner", "PlayerName");        // Ownership
set("no steal", 1);                // Cannot be stolen
set("no sell", 1);                 // Cannot be sold
set("undroppable", 1);             // Cannot be dropped
set("ungettable", 1);              // Cannot be picked up
~~~

- **charges**: Limits the number of uses.
- **light**: Makes the item emit light.
- **register event handler**: Enables custom event processing.
- **owner**: Binds the item to a specific player.
- **no steal/no sell/undroppable/ungettable**: Restricts item interactions.

**Tip:** Use these to create quest items, artifacts, or unique loot with special rules.

### Step 10: Material-Driven Descriptions

Material-driven descriptions make your items dynamic and immersive. You can 
use material placeholders in your item’s description, which are automatically 
replaced with the actual materials used.

~~~c
set("long", "This masterwork blade features a metal blade with an ornate metal 
crossguard. The hilt combines wood and leather wrapped with metal wire, topped 
by a metal pommel set with crystal.");
~~~

When viewed, this becomes:

> "This masterwork blade features a mithril blade with an ornate steel 
crossguard. The hilt combines koa wood and pegasus leather wrapped with gold 
wire, topped by a platinum pommel set with ruby."

**Tip:** This feature allows you to write generic descriptions that adapt 
to the actual materials chosen during crafting or item creation.

---

## 3. Full Example: Complex Weapon

Here is a complete example of a multi-material, enchanted weapon. This example 
demonstrates how to combine all the steps above into a single, fully-featured item.

~~~c
inherit "/lib/items/weapon.c";

protected void Setup()
{
    set("name", "Elemental Katana");
    set("short", "an elemental katana");
    set("blueprint", "katana");
    set("material", "mithril");
    set("primary crafting material", "mithril");
    set("primary component", "blade");
    set("craftsmanship", 92);

    set("crafting materials", ([
        "blade": ([
            "description": "a gracefully curved, single-edged blade...",
            "metal": "mithril",
            "type": "Curved Edge",
            "value": 200
        ]),
        "crossguard": ([
            "description": "Simple elegant crossguard",
            "metal": "steel",
            "type": "Simple",
            "value": 25
        ]),
        "hilt": ([
            "description": "Silk-wrapped handle bound with silver wire",
            "textile": "silk",
            "metal": "silver",
            "type": "Wrapped Grip",
            "value": 50
        ]),
        "pommel": ([
            "description": "Perfectly balanced metal sphere",
            "metal": "steel",
            "type": "Sphere",
            "value": 15
        ])
    ]));

    set("enchantments", ([
        "fire": 10,
        "cold": 10,
        "electrical": 10
    ]));

    set("weapon class", 5);
    set("bonus long sword", 3);
    set("value", 8000);
}
~~~

This item uses a blueprint, defines custom materials for each component, 
adds enchantments, bonuses, and sets a high craftsmanship value. The 
result is a unique, powerful weapon that stands out in the game.

---

## 4. Monster/Room Equipment Example

You can use the same structure to create equipment for monsters or place 
items in rooms. This allows for dynamic loot and world-building.

~~~c
void eventEquipment()
{
    object weapon = clone_object("/domains/castle/obj/guards-sword.c");
    weapon->set("material", "steel");
    weapon->set("craftsmanship", 60);
    weapon->set("crafting materials", ([
        "blade": ([
            "metal": "steel",
            "type": "Guard Pattern",
            "description": "a sturdy steel blade marked with the castle's seal"
        ])
    ]));
    this_object()->equip(weapon);
}
~~~

This example shows how to equip a monster with a custom sword, 
specifying its material, craftsmanship, and component details.

---

## 5. Reference Summary

For further customization and advanced features, refer to the following files and directories:

- **lib/items/item.c** - Base item functionality
- **lib/items/equipment.c** - Equipment mechanics
- **lib/items/weapon.c** - Weapon-specific properties
- **lib/items/armor.c** - Armor-specific properties
- **lib/services/materials/weapons.h** - Weapon blueprints
- **lib/services/materials/armor.h** - Armor blueprints
- **lib/services/materials/components.h** - Component definitions
- **lib/services/materials/materials.h** - Material properties
- **lib/services/materials/enchantments.h** - Enchantment definitions
- **lib/services/materialsService.c** - Material system
- **lib/services/craftingService.c** - Crafting system
- **lib/services/crafting/equipment-materials.c** - Material assignment
- **lib/services/crafting/enchantments.c** - Enchantment processing
- **lib/modules/crafting/selectMaterialsSelector.c** - Main crafting interface
- **lib/modules/crafting/componentSelector.c** - Component selection
- **lib/modules/crafting/materialSelector.c** - Material selection

---

**Summary:**  
To create equipment, start by choosing the correct inheritance, set a 
blueprint, and define your item's materials and components. Add core 
properties, bonuses, enchantments, prerequisites, and special 
behaviors as needed. Use the examples and property reference above 
to guide your design. The system is designed to be flexible, powerful, 
and easy to extend for any type of item you wish to create.

**Remember:** The more detail and creativity you put into your item 
definitions, the more engaging and rewarding the equipment will be for 
players. Take advantage of the system’s flexibility to create items that 
are not only mechanically interesting but also rich in lore and flavor.
