# equipment.md

#### Equipment System Overview

Equipment in this MUD represents a sophisticated multi-layered system that handles 
everything from simple iron swords to complex multi-material masterworks with 
enchantments. The system seamlessly integrates player crafting, monster equipment, 
and world-placed items through a unified component-based architecture.

The equipment system operates on three fundamental levels:
1. **Blueprint System**: Defines base item types and their core characteristics
2. **Materials System**: Determines how different materials affect item properties
3. **Crafting System**: Allows for component-based construction and customization

##### Equipment Inheritance Hierarchy

All equipment follows a strict inheritance chain that builds functionality in layers:

~~~c
inherit "/lib/items/equipment.c"; // For generic equipment
// OR
inherit "/lib/items/weapon.c";   // For weapons  
// OR
inherit "/lib/items/armor.c";    // For armor
~~~

This hierarchy means:
- **lib/items/item.c** provides basic item functionality (naming, identification, value)
- **lib/items/equipment.c** adds equipping mechanics, prerequisites, and bonuses
- **lib/items/weapon.c** and **lib/items/armor.c** add combat-specific properties and behaviors

##### System File Locations

The equipment system is defined across multiple files and directories:

###### Core System Files
- **lib/items/item.c** - Base item functionality
- **lib/items/equipment.c** - Equipment-specific functionality
- **lib/items/weapon.c** - Weapon-specific properties
- **lib/items/armor.c** - Armor-specific properties

###### Service Files
- **lib/services/materialsService.c** - Main materials system
- **lib/services/craftingService.c** - Crafting system integration

###### Blueprint Definitions
- **lib/services/materials/weapons.h** - All weapon blueprints
- **lib/services/materials/armor.h** - All armor blueprints
- **lib/services/materials/instruments.h** - Musical instrument blueprints
- **lib/services/materials/potions.h** - Potion and consumable blueprints
- **lib/services/materials/food.h** - Food item blueprints
- **lib/services/materials/drinks.h** - Drink item blueprints

###### Component System
- **lib/services/materials/components.h** - Component definitions and types
- **lib/services/materials/components/blueprints.c** - Blueprint processing
- **lib/services/materials/components/core.c** - Core component functionality
- **lib/services/materials/components/generate-component.c** - Component generation
- **lib/services/materials/components/generate-random-item.c** - Random item creation

###### Material Properties
- **lib/services/materials/materials.h** - All material definitions
- **lib/services/materials/components/general-properties.c** - General material properties
- **lib/services/materials/components/combat-properties.c** - Combat-related properties
- **lib/services/materials/components/item-statistics.c** - Item stat calculations
- **lib/services/materials/components/weapon-statistics.c** - Weapon stat calculations  
- **lib/services/materials/components/armor-statistics.c** - Armor stat calculations

###### Enchantment System
- **lib/services/materials/enchantments.h** - Enchantment definitions
- **lib/services/materials/components/enchantments.c** - Enchantment processing

###### Crafting System
- **lib/services/crafting/core.c** - Core crafting functionality
- **lib/services/crafting/blueprints.c** - Blueprint integration
- **lib/services/crafting/materials.c** - Material handling
- **lib/services/crafting/equipment-materials.c** - Equipment material assignment
- **lib/services/crafting/craft-item.c** - Item crafting logic
- **lib/services/crafting/enchantments.c** - Enchantment crafting
- **lib/services/crafting/generate-item.c** - Item generation

###### Crafting Interface
- **lib/modules/crafting/selectMaterialsSelector.c** - Main crafting interface
- **lib/modules/crafting/componentSelector.c** - Component selection
- **lib/modules/crafting/materialSelector.c** - Material selection
- **lib/modules/crafting/enchantmentSelector.c** - Enchantment selection
- **lib/modules/crafting/craftingSelector.c** - Crafting type selection
- **lib/modules/crafting/craftItemSelector.c** - Item selection

##### The Blueprint System

Every piece of equipment starts with a blueprint that defines its fundamental 
characteristics. Blueprints are stored in **lib/services/materials/weapons.h** 
(for weapons) and **lib/services/materials/armor.h** (for armor).

~~~c
set("blueprint", "long sword");
~~~

This single line connects your item to a blueprint entry defined in weapons.h:

~~~c
"long sword": ([
    "type": "weapon",
    "subtype": "sword",
    "default location": OnehandedWeapon,
    "damage type": "slash",
    "skill to use": "long sword",
    "default wc": 10,
    "default dc": 2,
    "default attack": 5,
    "default weight": 5,
    "default encumberance": 5,
    "default material": "iron",
    "default value": 200,
    "default description": "This is a sword with a blade that is about 40 inches (100 cm) long.",
    "crafting materials": ([
        "blade": (["metal": 6 ]),
        "crossguard": (["metal": 2, "crystal": 0 ]),
        "hilt": (["metal": 1, "wood": 1, "leather": 1 ]),
        "pommel": (["metal": 1, "crystal": 0 ]),
    ]),
    "skill to craft": 10,
    "crafting prerequisites": ([
        "/lib/instances/research/crafting/weapons/swords/craftLongSwords.c":
            (["type":"research"]),
        "blacksmithing": (["type":"skill", "value": 1]),
        "metal crafting": (["type":"skill", "value": 1]),
        "weapon smithing": (["type":"skill", "value": 8]),
    ]),
])
~~~

The blueprint system provides:
- **Default values** for all item properties
- **Crafting requirements** including skills and research
- **Material composition** defining what components the item uses
- **Base statistics** that materials and craftsmanship modify

##### Component System

Components are defined in **lib/services/materials/components.h** 
and define the parts that make up complex items:

~~~c
protected mapping craftingComponents = ([
    "blade": ([
        "type": "primary",
        "description": "the main cutting edge of the weapon",
        "value modifier": 1.5,
        "can use": ({ "metal" }),
        "experience modifier": 1.2,
    ]),
    "crossguard": ([
        "type": "secondary", 
        "description": "the hand protection of the weapon",
        "value modifier": 0.8,
        "can use": ({ "metal", "crystal" }),
        "experience modifier": 1.0,
    ]),
    "hilt": ([
        "type": "secondary",
        "description": "the handle of the weapon", 
        "value modifier": 0.3,
        "can use": ({ "metal", "wood", "leather" }),
        "experience modifier": 0.8,
    ]),
    "pommel": ([
        "type": "secondary",
        "description": "the counterweight of the weapon",
        "value modifier": 0.5,
        "can use": ({ "metal", "crystal" }),
        "experience modifier": 0.9,
    ]),
])
~~~

Each component defines:
- **Type**: Primary or secondary importance
- **Description**: How it appears in item descriptions
- **Value modifier**: How it affects item value
- **Allowed materials**: What material types can be used
- **Experience modifier**: Effect on crafting experience

##### Material System

Materials are defined in **lib/services/materials/materials.h**
and determine how different substances affect item properties:

~~~c
protected mapping materials = ([
    "iron": ([
        "type": "metal",
        "hardness": 10,
        "weight": 1.0,
        "value": 1.0,
        "description": "a common, durable metal",
        "craftsmanship": 10,
    ]),
    "steel": ([
        "type": "metal", 
        "hardness": 15,
        "weight": 1.0,
        "value": 2.0,
        "weapon class": 2,
        "armor class": 1,
        "description": "a strong metal alloy",
        "craftsmanship": 15,
    ]),
    "mithril": ([
        "type": "metal",
        "hardness": 25,
        "weight": 0.6,
        "value": 15.0,
        "weapon class": 4,
        "armor class": 3,
        "description": "a legendary lightweight metal",
        "craftsmanship": 25,
        "enchantable": 1,
    ]),
])
~~~

Material properties include:
- **Type**: Material category (metal, wood, leather, etc.)
- **Hardness**: Durability and effectiveness
- **Weight**: Weight multiplier
- **Value**: Cost multiplier
- **Combat bonuses**: Weapon class, armor class modifiers
- **Craftsmanship**: Maximum quality achievable
- **Special properties**: Enchantable, damage types, etc.

##### Enchantment System

Enchantments are defined in **lib/services/materials/enchantments.h**:

~~~c
protected mapping equipmentEnchantments = ([
    "fire": ([
        "type": "elemental",
        "description": "flames dance along the weapon's surface",
        "damage type": "fire",
        "skill required": "elemental fire",
        "research required": "/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c",
        "materials": ([
            "ruby": 1,
            "fire essence": 2,
        ]),
    ]),
    "sharpness": ([
        "type": "enhancement",
        "description": "the blade gleams with supernatural sharpness",
        "bonus": "weapon class",
        "skill required": "weapon smithing",
        "research required": "/lib/instances/research/crafting/enchantments/craftSharpness.c",
        "materials": ([
            "diamond": 1,
            "grinding stone": 3,
        ]),
    ]),
])
~~~

Enchantments provide:
- **Type**: Category of magical effect
- **Description**: How the enchantment appears
- **Effect**: Damage type or stat bonus
- **Requirements**: Skills and research needed
- **Materials**: Components required for enchanting

##### Simple Equipment Creation

For basic equipment that doesn't need complex materials, you can create 
items with minimal setup:

~~~c
inherit "/lib/items/weapon.c";

protected void Setup()
{
    set("name", "Long sword");
    set("short", "Long sword");
    set("aliases", ({ "sword", "longsword", "long sword" }));
    set("blueprint", "long sword");
}
~~~

This creates a weapon using all blueprint defaults:
- Material defaults to "iron" (from blueprint)
- Weapon class, defense class, and attack values come from blueprint
- Weight, encumbrance, and value are blueprint-derived
- The materials service automatically applies iron's properties

##### Advanced Equipment with Crafting Materials Structure

Equipment can be created with the full crafting materials structure, 
whether made through crafting or placed directly in the world:

~~~c
inherit "/lib/items/weapon.c";

protected void Setup()
{
    set("name", "Dragonslayer Blade");
    set("short", "a masterwork dragonslayer blade");
    set("aliases", ({ "blade", "sword", "dragonslayer" }));
    set("blueprint", "long sword");
    
    // Material properties
    set("material", "admantite");
    set("primary crafting material", "admantite");
    set("primary component", "blade");
    set("craftsmanship", 85);
    
    // Detailed component structure
    set("crafting materials", ([
        "blade": ([ 
            "description": "a broad, flat, metal blade with parallel edges "
                "and a lenticular cross-section. The fuller is narrow and "
                "runs half of the length of the blade, ending in a rounded "
                "point.", 
            "metal": "admantite", 
            "type": "Type XIII",
            "value": 110 
        ]), 
        "crossguard": ([ 
            "crystal": "ruby", 
            "description": "an ornate metal knuckleguard that has been "
                "sculpted to appear as though a dracolich with crystal eyes "
                "is protecting the user's hand.", 
            "metal": "galvorn", 
            "type": "Dracolich Form", 
            "value": 325 
        ]), 
        "hilt": ([ 
            "description": "a hilt of metal covered with a slightly ovular "
                "grip made out of wood and wrapped in spiraled metal wire.", 
            "leather": "pegasus leather", 
            "metal": "gold", 
            "type": "Spiral Hilt", 
            "value": 15, 
            "wood": "koa" 
        ]), 
        "pommel": ([ 
            "crystal": "ruby", 
            "description": "an exquisite metal pommel that has been "
                "intricately sculpted to resemble a dragon's talon. Clutched "
                "in its grip is a beautifully cut crystal.", 
            "metal": "platinum", 
            "type": "Dragon Talon", 
            "value": 50
        ])
    ]));
    
    // Additional properties
    set("weapon class", 3);         // Bonus above blueprint
    set("enchantments", ([
        "fire": 15,
        "magical": 5
    ]));
    set("bonus strength", 2);
    set("value", 5000);
}
~~~

##### Core Equipment Properties

###### Basic Item Properties (from lib/items/item.c)
- **name**: The item's primary name
- **short**: Short description displayed in inventories
- **aliases**: Alternative names players can use to reference the item
- **long**: Detailed description when examined
- **value**: Base monetary value
- **weight**: Physical weight affecting encumbrance
- **material**: What the item is made from (affects many properties)
- **craftsmanship**: Quality level of construction (1-100+)

###### Equipment-Specific Properties (from lib/items/equipment.c)
- **blueprint**: Defines the item's base type and characteristics
- **equipment locations**: Where the item can be equipped (bitfield)
- **prerequisites**: Requirements to equip the item
- **equip/unequip messages**: Custom messages for equipping actions
- **cursed**: Makes items difficult or impossible to remove

###### Weapon Properties (from lib/items/weapon.c)
- **weapon class**: Base damage potential
- **defense class**: Defensive bonus when wielded
- **weapon attack**: Attack speed/accuracy bonus
- **weapon type**: Skill category (sword, axe, etc.)
- **damage type**: Primary damage type (slash, thrust, bludgeon)

###### Armor Properties (from lib/items/armor.c)
- **armor class**: Base protection value
- **armor type**: Category affecting restrictions and bonuses

##### The Crafting Materials System

The `crafting materials` mapping allows detailed component specification. 
The structure is processed by **lib/services/crafting/equipment-materials.c**:

###### Component Structure
Each component (blade, crossguard, hilt, pommel, etc.) contains:

~~~c
"component_name": ([
    "description": "detailed description of this component",
    "material_type": "specific_material",  // e.g., "metal": "admantite"
    "type": "component_style",             // e.g., "Type XIII", "Dracolich Form"
    "value": additional_value              // Extra value from this component
])
~~~

###### Material Types
Components can use various material types as defined in **lib/services/materials/materials.h**:
- **metal**: steel, iron, admantite, mithril, galvorn, gold, platinum
- **wood**: oak, koa, ironwood, maple
- **leather**: leather, pegasus leather, dragon leather
- **crystal**: ruby, sapphire, diamond, emerald
- **textile**: silk, cotton, linen
- **stone**: granite, marble, obsidian

###### Component Types
Each component can have different styles/forms as defined in **lib/services/materials/components.h**:
- **Blade types**: Type X, Type XIII, Curved, Serrated
- **Crossguard types**: Simple, Ornate, Dracolich Form, Eagle Wing
- **Hilt types**: Spiral Hilt, Wrapped Grip, Carved Handle
- **Pommel types**: Dragon Talon, Sphere, Weighted

##### Combat Integration

Equipment integrates with the combat system defined in **lib/modules/combat.c**:

###### Combat Properties
- **weapon class**: Affects damage calculation in `calculateDamage()`
- **armor class**: Affects damage reduction in `calculateSoakDamage()`
- **weapon attack**: Modifies attack rolls in `calculateAttack()`
- **defense class**: Improves defensive calculations in `calculateDefendAttack()`

###### Enchantment Effects
- **Damage enchantments**: Add extra damage types to attacks
- **Resistance enchantments**: Reduce incoming damage of specific types
- **Stat bonuses**: Modify character attributes and skills

##### Equipment Examples

###### Simple Weapon
~~~c
inherit "/lib/items/weapon.c";

protected void Setup()
{
    set("name", "Iron sword");
    set("short", "an iron sword");
    set("blueprint", "long sword");
    set("material", "iron");
}
~~~

###### Complex Multi-Material Weapon
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
            "description": "a gracefully curved, single-edged blade that "
                "gleams with inner light",
            "metal": "mithril",
            "type": "Curved Edge",
            "value": 200
        ]),
        "crossguard": ([
            "description": "a simple yet elegant metal crossguard",
            "metal": "steel",
            "type": "Simple",
            "value": 25
        ]),
        "hilt": ([
            "description": "a silk-wrapped handle bound with silver wire",
            "textile": "silk",
            "metal": "silver",
            "type": "Wrapped Grip",
            "value": 50
        ]),
        "pommel": ([
            "description": "a perfectly balanced metal sphere",
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

##### Bonuses and Enchantments

###### Stat Bonuses
Equipment can provide bonuses to player attributes and skills:

~~~c
set("bonus strength", 2);          // +2 to strength
set("bonus long sword", 4);        // +4 to long sword skill
set("bonus hit points", 25);       // +25 maximum hit points
set("bonus armor class", 3);       // +3 armor class
~~~

###### Enchantments
Magical properties add damage types:

~~~c
set("enchantments", ([
    "fire": 15,                     // +15 fire damage
    "magical": 5,                   // +5 magical damage
    "cold": 10                      // +10 cold damage
]));
~~~

###### Resistances
Protection against specific damage types:

~~~c
set("resistances", ([
    "fire": 20,                     // 20% fire resistance
    "cold": 15,                     // 15% cold resistance
    "physical": 10                  // 10% physical resistance
]));
~~~

##### Prerequisites and Restrictions

Equipment can have requirements for use:

~~~c
set("prerequisites", ([
    "level": 15,                    // Minimum level
    "skills": ([ 
        "long sword": 10            // Minimum skill requirement
    ]),
    "guilds": ([
        "allowed": ({ "fighter", "paladin" })  // Guild restrictions
    ]),
    "research": ([
        "advanced swordplay": 1     // Research requirements
    ]),
    "race": "elf"                   // Race requirement
]));
~~~

##### Equipment Location System

Equipment locations use bitfield constants from **lib/include/inventory.h**:

- **OnehandedWeapon**: Primary weapon slot
- **TwohandedWeapon**: Two-handed weapon slot  
- **Shield**: Shield/offhand slot
- **Helmet**: Head protection
- **Armor**: Body armor
- **Gloves**: Hand protection
- **Boots**: Foot protection
- **Cloak**: Outer garment
- **Ring/Ring2**: Finger jewelry slots

##### Material-Driven Descriptions

Equipment descriptions can incorporate the actual materials used. 
This is processed by **lib/services/crafting/equipment-materials.c**:

~~~c
set("long", "This masterwork blade features a metal blade with an ornate "
    "metal crossguard. The hilt combines wood and leather wrapped with "
    "metal wire, topped by a metal pommel set with crystal.");
~~~

When viewed, this gets parsed / replaced with actual material names:
~~~"This masterwork blade features a mithril blade with an ornate steel
crossguard. The hilt combines koa wood and pegasus leather wrapped 
with gold wire, topped by a platinum pommel set with ruby."
~~~

The `addMaterialsToDescription()` method automatically replaces material 
placeholders with actual material names.

##### Monster and Room Equipment

Equipment created for monsters or placed in rooms uses the same structure:

~~~c
// In a monster file
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

##### Special Properties

Equipment can have unique characteristics:

~~~c
set("cursed", ([
    "equip message": "The sword adheres to your hand!",
    "failed unequip message": "The cursed blade will not release you!"
]));

set("charges", 50);                // Limited use items
set("light", 5);                   // Light source
set("register event handler", 1);  // Special event processing
~~~

##### Integration with Game Systems

Equipment integrates with:

**Combat**: Weapon class, armor class, bonuses affect all combat calculations in **lib/modules/combat.c**
**Skills**: Equipment provides skill bonuses and has skill requirements
**Magic**: Enchantments and resistances interact with spell systems
**Materials**: Complex material system affects properties and descriptions
**Economics**: Value calculations based on materials and craftsmanship
**Character Development**: Prerequisites tie equipment to character advancement

##### Reference Summary

###### Core Files
- **lib/items/item.c** - Base item functionality
- **lib/items/equipment.c** - Equipment mechanics
- **lib/items/weapon.c** - Weapon-specific properties
- **lib/items/armor.c** - Armor-specific properties

###### Definition Files
- **lib/services/materials/weapons.h** - Weapon blueprints
- **lib/services/materials/armor.h** - Armor blueprints
- **lib/services/materials/components.h** - Component definitions
- **lib/services/materials/materials.h** - Material properties
- **lib/services/materials/enchantments.h** - Enchantment definitions

###### Processing Files
- **lib/services/materialsService.c** - Material system
- **lib/services/craftingService.c** - Crafting system
- **lib/services/crafting/equipment-materials.c** - Material assignment
- **lib/services/crafting/enchantments.c** - Enchantment processing

###### Interface Files
- **lib/modules/crafting/selectMaterialsSelector.c** - Main crafting interface
- **lib/modules/crafting/componentSelector.c** - Component selection
- **lib/modules/crafting/materialSelector.c** - Material selection

This comprehensive system allows for equipment ranging from simple items to 
complex multi-material masterworks, whether created through player crafting 
or placed directly in the world by designers. The consistent structure 
ensures all equipment benefits from the same sophisticated material and
bonus systems while maintaining clear organization across the codebase.
