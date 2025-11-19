# Guild System Documentation

## Table of Contents

- [Overview](#overview)
- [Core Concepts](#core-concepts)
- [File Organization](#file-organization)
- [Creating a Guild](#creating-a-guild)
- [Guild Configuration](#guild-configuration)
- [Ranks System](#ranks-system)
- [Criteria System](#criteria-system)
- [Prerequisites](#prerequisites)
- [Guild Restrictions](#guild-restrictions)
- [Equipment Prohibitions](#equipment-prohibitions)
- [Complete Guild Examples](#complete-guild-examples)

---

## Overview

The guild system provides a comprehensive framework for creating character advancement paths 
through organized hierarchies. Guilds define how characters gain abilities, skills, and 
bonuses as they progress through levels and ranks.

### Key System Components

1. **Guild Definition** - The core guild configuration (name, class, preferences)
2. **Ranks System** - Hierarchical progression with titles and delays
3. **Criteria System** - Level and rank-based advancement rules
4. **Prerequisites** - Requirements for level/rank advancement
5. **Restrictions** - Guild combinations, equipment, and departure rules

---

## Core Concepts

### Guild vs Character Progression

- **Guild**: An organization that defines advancement rules and bonuses
- **Character Guild Membership**: A character's progression within a specific guild
- **Guild Level**: Character's level within the guild (1-1000)
- **Guild Rank**: Character's position in the guild hierarchy

### Guild Types

Guilds are categorized by class:
- `combat` - Combat-focused guilds (fighters, guards)
- `magic` - Spell-casting guilds (mages, sorcerers)
- `divine` - Religion-based guilds (priests, paladins)
- `trade` - Crafting and merchant guilds
- `stealth` - Thief and assassin guilds

### Advancement Mechanics

Characters advance through:
1. **Levels** - Earned through experience points
2. **Ranks** - Time-delayed promotions with prerequisites
3. **Bonuses** - Automatic stat/skill increases
4. **Research** - Unlocked abilities and trees

---

## File Organization

### Core System Files

| File | Purpose |
|------|---------|
| `lib/modules/guilds/baseGuild.c` | Base guild class - all guilds inherit from this |
| `lib/services/guildsService.c` | Guild management and validation service |
| `lib/modules/guilds.c` | Character guild membership module |

### Guild Structure

Each guild should be organized as:

```
guilds/<guild-name>/
  <guild-name>.c          # Main guild definition
  <research-tree-1>.c     # Research trees
  <research-tree-2>.c
  paths/                  # Optional: Path choices
    <path-1>.c
    <path-2>.c
  <subfolder>/            # Optional: Research organization
    <research-items>.c
```

---

## Creating a Guild

### Basic Guild Template

Every guild must inherit from `baseGuild.c` and implement `SetupGuild()`:

```
// File: /guilds/example/example.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    // Guild configuration goes here
    guildName("example guild");
    
    // Add criteria, ranks, restrictions, etc.
}
```

### Required Elements

Every guild must define:
1. **Guild Name** - Via `guildName()`
2. **Criteria** - At minimum: hit points, skill points, attribute points
3. **Starting Configuration** - Either default rank or custom rank system

### Optional Elements

Guilds may also define:
- Custom rank hierarchy
- Guild combination restrictions
- Equipment prohibitions
- Skill type preferences
- Level/rank prerequisites
- Special advancement rules

---

## Guild Configuration

### Setting Guild Name

```
guildName("fighter");
guildName("Aegis Guard");
guildName("Scion of Dhuras");
```

**Important**: Guild names are case-sensitive and must be unique.

### Setting Guild Class

```
guildClass("combat");    // Default if not specified
guildClass("magic");
guildClass("divine");
guildClass("trade");
guildClass("stealth");
```

### Preferred Skill Types

Define which skill categories cost 1 point instead of 2:

```
addPreferredSkillType("combat");
addPreferredSkillType("magic");
addPreferredSkillType("general");
addPreferredSkillType("crafting");
```

**Default**: All guilds get "general", "erudite", and "language" as preferred.

### Non-Combat Guilds

Mark guilds that should not engage in combat:

```
nonCombatGuild();
```

---

## Ranks System

### Rank Structure

Ranks create a hierarchical progression system with the following properties:

| Property | Description | Required |
|----------|-------------|----------|
| `name` | Internal rank identifier | Yes |
| `title` | Title shown after character name | No |
| `pretitle` | Title shown before character name | No |
| `previous rank` | Link to previous rank in chain | No |
| `next rank` | Link to next rank in chain | No |
| `delay for next promotion` | Hours before eligible for next rank | No |

### Adding Ranks

```
addRank("recruit", ([
    "name": "recruit", 
    "title": "of the Aegis Guard", 
    "pretitle": "Recruit", 
    "next rank": "guardsman"
]));

addRank("guardsman", ([
    "name": "guardsman", 
    "title": "of the Aegis Guard", 
    "pretitle": "", 
    "previous rank": "recruit", 
    "next rank": "corporal",
    "delay for next promotion": 1200  // 1200 hours = 50 days
]));

addRank("corporal", ([
    "name": "corporal", 
    "title": "of the Aegis Guard", 
    "pretitle": "Corporal", 
    "previous rank": "guardsman", 
    "next rank": "sergeant",
    "delay for next promotion": 3600  // 3600 hours = 150 days
]));
```

### Setting Default Rank

Define the starting rank for new guild members:

```
setDefaultRank("recruit");
setDefaultRank("neophyte");
```

If no custom ranks are defined, characters start with "default" rank.

### Rank Delays

The `delay for next promotion` specifies minimum real-world time (in hours) 
before a character can advance to the next rank:

- 24 hours = 1 day
- 168 hours = 1 week
- 720 hours = 30 days
- 1200 hours = 50 days
- 3600 hours = 150 days
- 7200 hours = 300 days

### Rank Prerequisites

Add requirements for advancing to specific ranks:

```
addRankPrerequisite("sergeant", ([
    "long sword": ([
        "type": "skill",
        "value": 25
    ]),
    "level": ([
        "type": "level",
        "guild": "Aegis Guard",
        "value": 10
    ])
]));
```

---

## Criteria System

The criteria system defines what characters gain as they level up. Criteria can be applied:
- Every level
- Every N levels
- At a specific level
- At a specific rank

### Valid Criteria Types

| Type | Purpose | Example |
|------|---------|---------|
| `modifier` | Modifies character stats | Hit points, spell points, stamina |
| `skill` | Increases skill values | Weapon skills, magic skills |
| `skill points` | Spendable skill points | General skill advancement |
| `attribute points` | Spendable attribute points | Strength, intelligence, etc. |
| `research points` | Spendable research points | Learning abilities |
| `research` | Grants specific research | Auto-learn an ability |
| `research tree` | Unlocks research tree | Opens ability tree |
| `research path` | One-time tree choice | Choose from multiple options |
| `research choice` | Repeating choice | Choose from options multiple times |
| `trait` | Grants personality trait | Behavioral modifiers |
| `attack` | Extra attacks per round | Combat bonus |

### Criteria Application Patterns

#### Every Level

```
addCriteria("hit points", ([
    "type": "modifier",
    "apply": "5 every level",
    "begin at level": 1
]));
```

#### Every N Levels

```
addCriteria("attribute points", ([
    "type": "attribute points",
    "apply": "1 every 5 levels"
]));

addCriteria("weapon attack", ([
    "type": "attack",
    "apply": "1 every 15 levels"
]));
```

#### At Specific Level

```
addCriteria("initial research points", ([
    "type": "research points",
    "apply": "5 at level 1"
]));

addCriteria("fireball", ([
    "type": "research",
    "apply": "at level 10",
    "research object": "/guilds/mage/fire/fireball.c"
]));
```

#### At Specific Rank

```
addCriteria("leadership", ([
    "type": "trait",
    "apply": "at rank general",
    "trait object": "/lib/instances/traits/personality/leadership.c"
]));
```

### Modifier Criteria

Modifiers affect character statistics:

```
addCriteria("hit points", ([
    "type": "modifier",
    "apply": "5 every level",
    "begin at level": 1
]));

addCriteria("spell points", ([
    "type": "modifier",
    "apply": "3 every level",
    "begin at level": 1
]));

addCriteria("stamina points", ([
    "type": "modifier",
    "apply": "4 every level",
    "begin at level": 1
]));
```

**Common modifiers**: `hit points`, `spell points`, `stamina points`

### Skill Criteria

Automatically increase specific skills:

```
addCriteria("spellcraft", ([
    "type": "skill",
    "apply": "3 every 2 levels"
]));

addCriteria("long sword", ([
    "type": "skill",
    "apply": "1 every level",
    "begin at level": 1,
    "end at level": 10
]));
```

### Point Criteria

Grant spendable points for player choice:

```
// Skill points - spend on any skill
addCriteria("skill points", ([
    "type": "skill points",
    "apply": "5 every level"
]));

// Attribute points - spend on any attribute
addCriteria("attribute points", ([
    "type": "attribute points",
    "apply": "1 every 5 levels"
]));

// Research points - spend on research
addCriteria("research points", ([
    "type": "research points",
    "apply": "1 every level"
]));
```

### Research Criteria

Automatically grant specific research:

```
addCriteria("fireball", ([
    "type": "research",
    "apply": "at level 5",
    "research object": "/guilds/mage/fire/fireball.c"
]));
```

### Research Tree Criteria

Unlock research trees for exploration:

```
addCriteria("blade attacks", ([
    "type": "research tree",
    "apply": "at level 1",
    "research tree": "/guilds/fighter/blade-attacks.c"
]));

addCriteria("advanced magic", ([
    "type": "research tree",
    "apply": "at level 15",
    "research tree": "/guilds/mage/advanced-magic.c"
]));
```

### Research Path Criteria

One-time choice from multiple research trees:

```
addCriteria("weapon focus", ([
    "type": "research path",
    "name": "The Focus",
    "description": "Choose your weapon focus",
    "apply": "at level 1",
    "research objects": ({ 
        "/guilds/scion/paths/sword.c",
        "/guilds/scion/paths/dagger.c",
        "/guilds/scion/paths/axe.c", 
        "/guilds/scion/paths/mace.c"
    })
]));
```

**Note**: Character chooses ONE from the list.

### Research Choice Criteria

Choice that can be selected multiple times:

```
addCriteria("spell specialization", ([
    "type": "research choice",
    "name": "Spell Specialization",
    "description": "Choose a spell specialization",
    "apply": "1 every 10 levels",
    "research objects": ({
        "/guilds/mage/specializations/fire.c",
        "/guilds/mage/specializations/ice.c",
        "/guilds/mage/specializations/lightning.c"
    })
]));
```

### Conditional Research

Apply research only if other research was chosen:

```
// Apply if specific research was chosen
addCriteria("flame blade enhancement", ([
    "type": "research tree",
    "apply": "at level 10",
    "apply if chosen": ({ "/guilds/scion/paths/sword.c" }),
    "research tree": "/guilds/scion/paths/sword/flame.c"
]));

// Apply if ANY of the listed research was chosen
addCriteria("avatar tree", ([
    "type": "research tree",
    "apply": "at level 1",
    "apply if any chosen": ({
        "/guilds/scion/paths/axe/blood.c",
        "/guilds/scion/paths/sword/blood.c",
        "/guilds/scion/paths/staff/blood.c"
    }),
    "research tree": "/guilds/scion/avatars/blood-avatar.c"
]));
```

### Attack Criteria

Grant extra attacks per combat round:

```
// Generic weapon attack
addCriteria("weapon attack", ([
    "type": "attack",
    "apply": "1 every 15 levels"
]));

// Specific attack type with base damage
addCriteria("fire attack", ([
    "type": "attack",
    "base damage": 25,
    "apply": "1 every 20 levels",
    "begin at level": 10
]));
```

### Trait Criteria

Grant personality or behavioral traits:

```
addCriteria("leadership", ([
    "type": "trait",
    "apply": "at rank general",
    "trait object": "/lib/instances/traits/personality/leadership.c"
]));
```

### Criteria with Begin/End

Limit criteria to specific level ranges:

```
addCriteria("long sword", ([
    "type": "skill",
    "apply": "1 every level",
    "begin at level": 5,
    "end at level": 20
]));
```

### Criteria with Rank Restrictions

Apply only during specific rank:

```
addCriteria("officer bonus", ([
    "type": "modifier",
    "apply": "10 every level",
    "begin at rank": "lieutenant"
]));
```

---

## Prerequisites

Prerequisites define requirements for advancing levels or ranks.

### Level Prerequisites

Requirements for advancing to a specific level:

```
addLevelPrerequisite(10, ([
    "long sword": ([
        "type": "skill",
        "value": 25
    ]),
    "strength": ([
        "type": "attribute",
        "value": 15
    ])
]));
```

### Rank Prerequisites

Requirements for advancing to a specific rank:

```
addRankPrerequisite("sergeant", ([
    "leadership quest": ([
        "type": "quest"
    ]),
    "level": ([
        "type": "level",
        "guild": "Aegis Guard",
        "value": 8
    ])
]));
```

### Valid Prerequisite Types

Same as research prerequisites:
- `level` - Character or guild level
- `skill` - Skill value requirement
- `attribute` - Attribute value requirement
- `research` - Must have researched ability
- `quest` - Must have completed quest
- `guild` - Guild membership
- `race` - Race requirement
- `trait` - Must have trait
- `combat statistic` - Combat achievements

---

## Guild Restrictions

### Prohibited Guild Combinations

Prevent joining incompatible guilds:

```
prohibitedGuildCombinations(({ "fighter", "monk", "Aegis Guard" }));
```

**Effect**: Characters cannot be members of this guild AND any of the listed guilds simultaneously.

### Preventing Guild Departure

Prevent leaving the guild:

```
prohibitLeavingGuild();
```

**Note**: Characters can still be expelled or leave if anathema.

### Preventing Re-joining

Prevent re-joining after leaving:

```
DoNotAllowReJoinOfGuild();
```

**Effect**: Once a character leaves, they can never rejoin.

---

## Equipment Prohibitions

Guilds can restrict equipment types based on various criteria.

### Material Prohibition

```
addEquipmentProhibition("material", ({ "iron", "steel", "mithril" }));
```

### Material Type Prohibition

```
addEquipmentProhibition("material type", ({ "metal", "leather" }));
```

### Armor Type Prohibition

```
addEquipmentProhibition("armor type", ({ "plate armor", "chain mail" }));
```

### Armor Location Prohibition

```
addEquipmentProhibition("armor location", ({ "head", "hands", "feet" }));
```

### Weapon Type Prohibition

```
addEquipmentProhibition("weapon type", ({ "sword", "axe", "bow" }));
```

### Damage Type Prohibition

```
addEquipmentProhibition("damage type", ({ "slashing", "piercing" }));
```

---

## Complete Guild Examples

### Example 1: Simple Combat Guild

A basic fighter-style guild with minimal complexity:

```
// File: /guilds/fighter/fighter.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("fighter");
    addPreferredSkillType("combat");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "Aegis Guard" }));

    // Resource progression
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "6 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "4 every level",
        "begin at level": 1
    ]));

    // Combat progression
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 15 levels"
    ]));

    // Spendable points
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    // Research trees
    addCriteria("blade attacks", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/blade-attacks.c"
    ]));

    addCriteria("axe attacks", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/axe-attacks.c"
    ]));

    addCriteria("shields", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/fighter/shields.c"
    ]));
}
```

### Example 2: Magic Guild

A spell-casting guild with research points:

```
// File: /guilds/aeromancer/aeromancer.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("aeromancer");
    addPreferredSkillType("combat");
    addPreferredSkillType("magic");

    // Resource progression - mage-focused
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    // Spendable points
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    // Magic trees
    addCriteria("lightning", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/aeromancer/lightning.c"
    ]));

    addCriteria("air", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/aeromancer/air.c"
    ]));
}
```

### Example 3: Guild with Rank System

A military-style guild with hierarchical ranks:

```
// File: /guilds/aegis-guard/aegis-guard.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Aegis Guard");
    addPreferredSkillType("combat");

    // Define rank hierarchy
    addRank("recruit", ([
        "name": "recruit", 
        "title": "of the Aegis Guard", 
        "pretitle": "Recruit", 
        "next rank": "guardsman"
    ]));

    addRank("guardsman", ([
        "name": "guardsman", 
        "title": "of the Aegis Guard", 
        "pretitle": "", 
        "previous rank": "recruit", 
        "next rank": "corporal",
        "delay for next promotion": 1200
    ]));

    addRank("corporal", ([
        "name": "corporal", 
        "title": "of the Aegis Guard", 
        "pretitle": "Corporal", 
        "previous rank": "guardsman", 
        "next rank": "sergeant",
        "delay for next promotion": 3600
    ]));

    addRank("sergeant", ([
        "name": "sergeant", 
        "title": "of the Aegis Guard", 
        "pretitle": "Sergeant", 
        "previous rank": "corporal", 
        "next rank": "lieutenant",
        "delay for next promotion": 3600
    ]));

    addRank("lieutenant", ([
        "name": "lieutenant", 
        "title": "of the Aegis Guard", 
        "pretitle": "Lieutenant", 
        "previous rank": "sergeant", 
        "next rank": "captain",
        "delay for next promotion": 3600
    ]));

    addRank("captain", ([
        "name": "captain", 
        "title": "of the Aegis Guard", 
        "pretitle": "Captain", 
        "previous rank": "lieutenant", 
        "next rank": "general",
        "delay for next promotion": 7200
    ]));

    addRank("general", ([
        "name": "general", 
        "title": "of the Aegis Guard", 
        "pretitle": "General", 
        "previous rank": "captain"
    ]));

    setDefaultRank("recruit");
    prohibitedGuildCombinations(({ "Scion of Dhuras", "fighter", "monk" }));

    // Resources
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "2 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    // Combat
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 15 levels"
    ]));

    // Points
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    addCriteria("initial research points", ([
        "type": "research points",
        "apply": "at level 1"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type": "research points",
        "apply": "2 every 5 levels"
    ]));

    // Research trees
    addCriteria("sword attacks", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/aegis-guard/sword-attacks.c"
    ]));

    addCriteria("combinations", ([
        "type": "research tree",
        "apply": "at level 5",
        "research tree": "/guilds/aegis-guard/sword-combinations.c"
    ]));

    addCriteria("elemental", ([
        "type": "research tree",
        "apply": "at level 11",
        "research tree": "/guilds/aegis-guard/sword-elemental.c"
    ]));
}
```

### Example 4: Guild with Path Choices

A guild with initial path selection and conditional advancement:

```
// File: /guilds/scion/scionOfDhuras.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("Scion of Dhuras");
    addPreferredSkillType("combat");

    // Rank system
    addRank("neophyte", ([
        "name": "neophyte", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Neophyte", 
        "next rank": "acolyte",
        "delay for next promotion": 1200
    ]));

    addRank("acolyte", ([
        "name": "acolyte", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Acolyte", 
        "previous rank": "neophyte", 
        "next rank": "adept",
        "delay for next promotion": 3600
    ]));

    addRank("adept", ([
        "name": "adept", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Adept", 
        "previous rank": "acolyte", 
        "next rank": "master",
        "delay for next promotion": 7200
    ]));

    addRank("master", ([
        "name": "master", 
        "title": "the Scion of Dhuras", 
        "pretitle": "Master", 
        "previous rank": "adept"
    ]));

    setDefaultRank("neophyte");
    prohibitedGuildCombinations(({ "Aegis Guard", "fighter", "monk" }));

    // Resources
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "4 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "4 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "2 every level",
        "begin at level": 1
    ]));

    // Combat and skills
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 15 levels"
    ]));

    addCriteria("spellcraft", ([
        "type": "skill",
        "apply": "3 every 2 levels"
    ]));

    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    // Weapon focus choice (one-time at level 1)
    addCriteria("weapon focus", ([
        "type": "research path",
        "name": "The Focus",
        "description": "Choose your weapon focus",
        "apply": "at level 1",
        "research objects": ({ 
            "/guilds/scion/paths/sword.c",
            "/guilds/scion/paths/dagger.c",
            "/guilds/scion/paths/axe.c", 
            "/guilds/scion/paths/mace.c",
            "/guilds/scion/paths/hammer.c",
            "/guilds/scion/paths/staff.c" 
        })
    ));

    // Magical path for sword users
    addCriteria("magical sword path", ([
        "type": "research choice",
        "name": "The Path (Sword)",
        "description": "Choose your magical path",
        "apply": "at level 1",
        "apply if chosen": ({ "/guilds/scion/paths/sword.c" }),
        "research objects": ({ 
            "/guilds/scion/paths/sword/flame.c",
            "/guilds/scion/paths/sword/electricity.c",
            "/guilds/scion/paths/sword/ice.c",
            "/guilds/scion/paths/sword/blood.c",
            "/guilds/scion/paths/sword/evocation.c",
            "/guilds/scion/paths/sword/spirit.c" 
        })
    ));

    // Conditional tree unlocking based on magical path
    addCriteria("flame avatar tree", ([
        "type": "research tree",
        "apply": "at level 1",
        "apply if any chosen": ({
            "/guilds/scion/paths/axe/flame.c",
            "/guilds/scion/paths/dagger/flame.c",
            "/guilds/scion/paths/sword/flame.c",
            "/guilds/scion/paths/staff/flame.c"
        }),
        "research tree": "/guilds/scion/avatars/flame-avatar.c"
    ));

    addCriteria("ice avatar tree", ([
        "type": "research tree",
        "apply": "at level 1",
        "apply if any chosen": ({
            "/guilds/scion/paths/axe/ice.c",
            "/guilds/scion/paths/dagger/ice.c",
            "/guilds/scion/paths/sword/ice.c",
            "/guilds/scion/paths/staff/ice.c"
        }),
        "research tree": "/guilds/scion/avatars/ice-avatar.c"
    ));
}
```

### Example 5: Guild with Equipment Restrictions

A guild that restricts certain equipment types:

```
// File: /guilds/monk/monk.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("monk");
    addPreferredSkillType("combat");
    prohibitedGuildCombinations(({ "fighter", "Aegis Guard", "bard" }));

    // Equipment prohibitions
    addEquipmentProhibition("material type", ({ "metal" }));
    addEquipmentProhibition("armor type", ({ 
        "plate armor", 
        "splint mail", 
        "chain mail", 
        "scale mail" 
    }));
    addEquipmentProhibition("weapon type", ({ 
        "sword", 
        "axe", 
        "mace", 
        "flail" 
    }));

    // Resources
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "6 every level",
        "begin at level": 1
    ]));

    // Unarmed combat focus
    addCriteria("unarmed attack", ([
        "type": "attack",
        "base damage": 15,
        "apply": "1 every 10 levels"
    ]));

    addCriteria("martial arts", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/monk/martial-arts.c"
    ]));

    addCriteria("ki abilities", ([
        "type": "research tree",
        "apply": "at level 5",
        "research tree": "/guilds/monk/ki-abilities.c"
    ]));
}
```

### Example 6: Hybrid Guild with Multiple Progressions

A guild mixing combat and magic with conditional advancement:

```
// File: /guilds/bard/bard.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("bard");
    addPreferredSkillType("combat");
    addPreferredSkillType("performance");
    prohibitedGuildCombinations(({ "monk" }));

    // Balanced resources
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "4 every level",
        "begin at level": 1
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    addCriteria("stamina points", ([
        "type": "modifier",
        "apply": "3 every level",
        "begin at level": 1
    ]));

    // Moderate combat ability
    addCriteria("weapon attack", ([
        "type": "attack",
        "apply": "1 every 20 levels"
    ]));

    // Spendable points
    addCriteria("attribute points", ([
        "type": "attribute points",
        "apply": "1 every 5 levels"
    ]));

    addCriteria("skill points", ([
        "type": "skill points",
        "apply": "5 every level"
    ]));

    // Generous research points for songs
    addCriteria("initial research points", ([
        "type": "research points",
        "apply": "5 at level 1"
    ]));

    addCriteria("research points", ([
        "type": "research points",
        "apply": "1 every level"
    ]));

    addCriteria("supplemental research points", ([
        "type": "research points",
        "apply": "2 every 5 levels"
    ]));

    // Core composition ability
    addCriteria("compose songs", ([
        "type": "research",
        "apply": "at level 1",
        "research object": "/guilds/bard/compositions/compose-song.c"
    ]));

    addCriteria("stop performance", ([
        "type": "research",
        "apply": "at level 1",
        "research object": "/guilds/bard/compositions/stop-performance.c"
    ]));

    // Combat options
    addCriteria("melee weapons", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/melee-attacks.c"
    ]));

    addCriteria("bows", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/bows.c"
    ]));

    // Performance options
    addCriteria("compositions", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/compositions.c"
    ]));

    addCriteria("lyrics", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/lyrics.c"
    ]));

    addCriteria("strings", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/strings.c"
    ]));

    addCriteria("woodwind-brass", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/woodwind-brass.c"
    ]));

    addCriteria("percussion", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/bard/percussion.c"
    ]));
}
```

### Example 7: Guild with Level Prerequisites

A guild requiring specific achievements for advancement:

```
// File: /guilds/archmage/archmage.c
inherit "/lib/modules/guilds/baseGuild.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupGuild()
{
    guildName("archmage");
    addPreferredSkillType("magic");

    // Resources
    addCriteria("hit points", ([
        "type": "modifier",
        "apply": "2 every level"
    ]));

    addCriteria("spell points", ([
        "type": "modifier",
        "apply": "8 every level"
    ]));

    // Level 5 requires elemental mastery
    addLevelPrerequisite(5, ([
        "elemental fire": ([
            "type": "skill",
            "value": 20
        ]),
        "spellcraft": ([
            "type": "skill",
            "value": 25
        ])
    ]));

    // Level 10 requires advanced magic
    addLevelPrerequisite(10, ([
        "/guilds/mage/advanced/fireball.c": ([
            "type": "research"
        ]),
        "intelligence": ([
            "type": "attribute",
            "value": 18
        ])
    ]));

    // Level 15 requires master quest
    addLevelPrerequisite(15, ([
        "arcane mastery quest": ([
            "type": "quest"
        ])
    ]));

    addCriteria("elemental magic", ([
        "type": "research tree",
        "apply": "at level 1",
        "research tree": "/guilds/archmage/elemental.c"
    ]));
}
```

---

## Best Practices

### Guild Design Guidelines

1. **Balance Resources**: Ensure hit points, spell points, and stamina are appropriate for guild role
2. **Consistent Point Awards**: Most guilds give 5 skill points per level, 1 attribute point every 5 levels
3. **Research Points**: Combat guilds typically get fewer than magic guilds
4. **Attack Progression**: Standard is 1 extra attack every 15-20 levels
5. **Research Trees**: Start with 1-3 trees at level 1, add more at higher levels

### Common Patterns

**Combat Guild**:
- High hit points (5-6 per level)
- High stamina (3-4 per level)
- Low/no spell points
- Weapon attack bonuses
- Combat research trees

**Magic Guild**:
- Low hit points (2-3 per level)
- High spell points (5-8 per level)
- Low stamina
- Many research points
- Spell research trees

**Hybrid Guild**:
- Moderate all resources (3-4 per level)
- Moderate research points
- Balanced combat and magic trees

### Naming Conventions

- Use lowercase for single-word guilds: `fighter`, `mage`, `bard`
- Use title case for multi-word guilds: `Aegis Guard`, `Scion of Dhuras`
- Keep names thematically appropriate and unique

### File Organization

- Place guild files in `/guilds/<guild-name>/`
- Use descriptive names for research trees
- Organize related research in subfolders
- Use consistent naming for paths/choices

### Testing Checklist

- [ ] Guild name is unique
- [ ] All research tree paths exist
- [ ] Rank chain is complete (if using ranks)
- [ ] Prerequisites are valid
- [ ] Equipment prohibitions are valid materials/types
- [ ] Prohibited guild combinations exist
- [ ] Resource progression is balanced
- [ ] All criteria apply correctly

---

## Common Mistakes

### Broken Rank Chains

**Wrong**:
```
addRank("recruit", ([
    "name": "recruit",
    "next rank": "corporal"  // Skips guardsman
]));

addRank("guardsman", ([
    "name": "guardsman",
    "previous rank": "recruit",
    "next rank": "corporal"
]));
```

**Right**:
```
addRank("recruit", ([
    "name": "recruit",
    "next rank": "guardsman"
]));

addRank("guardsman", ([
    "name": "guardsman",
    "previous rank": "recruit",
    "next rank": "corporal"
]));
```

### Invalid Research Paths

**Wrong**:
```
addCriteria("fire tree", ([
    "type": "research tree",
    "apply": "at level 1",
    "research tree": "/guilds/mage/fire.c"  // File doesn't exist
]));
```

**Right**: Ensure all research tree files exist before referencing them.

### Forgetting setDefaultRank

**Wrong**:
```
addRank("recruit", ([...]));
addRank("corporal", ([...]));
// Missing setDefaultRank() - characters won't join!
```

**Right**:
```
addRank("recruit", ([...]));
addRank("corporal", ([...]));
setDefaultRank("recruit");
```

### Invalid Apply Syntax

**Wrong**:
```
addCriteria("hit points", ([
    "type": "modifier",
    "apply": "every level 5"  // Wrong syntax
]));
```

**Right**:
```
addCriteria("hit points", ([
    "type": "modifier",
    "apply": "5 every level"  // Correct: <amount> every <frequency> level(s)
]));
```

### Mismatched Criteria Types

**Wrong**:
```
addCriteria("fireball", ([
    "type": "research tree",  // Wrong type
    "apply": "at level 5",
    "research object": "/guilds/mage/fireball.c"
]));
```

**Right**:
```
addCriteria("fireball", ([
    "type": "research",  // Correct for single research
    "apply": "at level 5",
    "research object": "/guilds/mage/fireball.c"
]));
```

---

## Advanced Topics

### Dynamic Rank Bonuses

Bonuses can be tied to ranks instead of levels:

```
addCriteria("leadership bonus", ([
    "type": "modifier",
    "apply": "10 every level",
    "begin at rank": "lieutenant"
]));
```

This grants +10 per level, but only after reaching lieutenant rank.

### Conditional Research Chains

Create research that only appears if prerequisites are met:

```
// Base choice
addCriteria("weapon path", ([
    "type": "research path",
    "name": "Weapon Path",
    "apply": "at level 1",
    "research objects": ({ 
        "/guilds/example/sword.c",
        "/guilds/example/axe.c"
    })
]));

// Sword-specific advancement
addCriteria("advanced sword", ([
    "type": "research tree",
    "apply": "at level 10",
    "apply if chosen": ({ "/guilds/example/sword.c" }),
    "research tree": "/guilds/example/advanced-sword.c"
]));

// Axe-specific advancement
addCriteria("advanced axe", ([
    "type": "research tree",
    "apply": "at level 10",
    "apply if chosen": ({ "/guilds/example/axe.c" }),
    "research tree": "/guilds/example/advanced-axe.c"
]));
```

### Multiple Choice Points

Allow repeated selections from a list:

```
addCriteria("specialization", ([
    "type": "research choice",
    "name": "Choose Specialization",
    "description": "Select an area of expertise",
    "apply": "1 every 10 levels",
    "research objects": ({
        "/guilds/example/spec-fire.c",
        "/guilds/example/spec-ice.c",
        "/guilds/example/spec-lightning.c"
    })
]));
```

At levels 10, 20, 30, etc., the character chooses one from the list.

### Experience Multipliers

The base guild uses a default experience formula:

```
Experience to next level = current level * 1000
```

This is currently not modifiable per guild, but affects all guilds equally.
