# Research System Documentation

## Table of Contents

- [Overview](#overview)
- [Core Concepts](#core-concepts)
- [File Organization](#file-organization)
- [Research Types](#research-types)
- [Prerequisites](#prerequisites)
- [Limiters](#limiters)
- [Research Trees](#research-trees)
- [Learning Types](#learning-types)
- [Common Specifications](#common-specifications)
- [Research Enhancement Systems](#research-enhancement-systems)
- [Active Research Specifications](#active-research-specifications)
- [Passive Research Specifications](#passive-research-specifications)
- [Sustained Research Specifications](#sustained-research-specifications)
- [Ritual Research Specifications](#ritual-research-specifications)
- [Knowledge Research Specifications](#knowledge-research-specifications)
- [Constructed Research Specifications](#constructed-research-specifications)
- [Composite Research Specifications](#composite-research-specifications)
- [Summoning Research Specifications](#summoning-research-specifications)
- [Complete Research Examples](#complete-research-examples)

---

## Overview

The research system is a comprehensive character advancement mechanism that enables characters to learn and utilize 
abilities, skills, and knowledge. Characters can learn research through various methods (research points, 
time-based learning, automatic grants, or as tree roots), and then use these abilities based on their type and scope.

### Key System Components

1. **Research Items** - Individual abilities, skills, or knowledge
2. **Research Trees** - Hierarchical organization of related research with prerequisite chains
3. **Prerequisites** - Requirements that must be met to LEARN research
4. **Limiters** - Conditions that must be met to USE research (different from prerequisites)
5. **Learning Methods** - How research is acquired (points, time, granted, tree root)
6. **Enhancement Systems** - How research items can modify or enhance other research

---

## Core Concepts

### Research Items vs Research Trees

- **Research Item**: A single learnable ability, skill, passive bonus, or piece of knowledge
- **Research Tree**: A hierarchical structure organizing related research items with parent-child relationships

### Prerequisites vs Limiters

- **Prerequisites**: Requirements to LEARN a research item (level, skills, completed quests, etc.)
- **Limiters**: Conditions that must be met to USE a research item after it's learned (location, time of day, weather, etc.)

### Active vs Passive Research

- **Active**: Abilities that must be triggered by the player using commands
- **Passive**: Bonuses that are always active once learned

### Scope

Defines who/what is affected by research:

- `self` - Affects only the user
- `targeted` - Affects a single target
- `area` - Affects everyone in the same location
- `environmental` - Affects the environment/room itself
- `region` - Affects an entire region
- `global` - Global effects
- `domain` - Domain/territory specific

---

## File Organization

### Core System Files

| File | Purpose |
|------|---------|
| `lib/modules/research/researchItem.c` | Base research item class - all research inherits from this |
| `lib/modules/research.c` | Character research management module |
| `lib/modules/secure/research.h` | Data structures and persistence |
| `lib/services/researchService.c` | Research service and caching |
| `lib/core/prerequisites.c` | Prerequisite validation system |
| `lib/core/specification.c` | Base specification and limiter system |

### Primary Research Type Classes

| File | Type | Description |
|------|------|-------------|
| `activeResearchItem.c` | active | Base for all active abilities |
| `passiveResearchItem.c` | passive | Always-active bonuses |
| `sustainedResearchItem.c` | sustained | Toggle-able maintained effects |
| `ritualResearchItem.c` | ritual | Complex abilities requiring preparation |
| `knowledgeResearchItem.c` | knowledge | Informational unlocks and lore |
| `constructedActiveResearchItem.c` | constructed (root) | Modular spell construction system root |
| `constructedResearchComponent.c` | constructed (component) | Components for constructed spells |

### Active Research Variants

Active research has several specialized variants for different effect delivery mechanisms:

| File | Specialization | Use Case |
|------|----------------|----------|
| `instantaneousActiveResearchItem.c` | Instant effects | Most common - immediate one-time effects (damage, healing, buffs) |
| `persistedActiveResearchItem.c` | Persisted world effects | Creates lasting effects in the game world |
| `instantaneousPersistedActiveResearchItem.c` | Instant + persisted | Combines immediate effect with world persistence |
| `combinedInstantaneousActiveResearchItem.c` | Combo chains | Multiple abilities chained together |
| `compositeActiveResearchItem.c` | Pre-built compositions | Songs, attack sequences with defined structures |
| `summoningResearchItem.c` | Summoning | Summons creatures or companions |

### Effect Definition Files

| File | Purpose |
|------|---------|
| `instantaneousEffect.c` | Defines damage/healing formulas for instant effects |
| `combinedInstantaneousEffect.c` | Effect definitions for combo chains |
| `effectModifier.c` | Effect modification system for sustained/constructed research |

### Research Tree Files

| File | Purpose |
|------|---------|
| `researchTree.c` | Tree structure, hierarchy management, prerequisite chains |
| `researchSelector.c` | Interactive selection interface for research trees |
| `researchSubselector.c` | Sub-selection mechanics for tree navigation |

### Support Files

| File | Purpose |
|------|---------|
| `compositeResearchTemplate.c` | Template definitions for composite research (songs) |
| `lib/services/bonusesService.c` | Validates all bonus types and modifiers |
| `lib/services/limitor.c` | Limiter validation service |
| `lib/services/attacks.c` | Attack and damage type definitions |

---

## Research Types

The system supports **seven primary research types**, each serving different gameplay purposes. All research types must inherit from the appropriate base class and set their type specification.

### Type Validation

From `researchItem.c`, the valid type values are:

- `"active"` - Must inherit `activeResearchItem.c`
- `"passive"` - Must inherit `passiveResearchItem.c`
- `"sustained"` - Must inherit `sustainedResearchItem.c`
- `"ritual"` - Must inherit `ritualResearchItem.c`
- `"knowledge"` - Must inherit `knowledgeResearchItem.c`
- `"constructed"` - Must inherit `constructedResearchComponent.c`
- `"domain"` - Must inherit `/lib/modules/domains/domainResearchItem.c`

### 1. Active Research

**Type**: `"active"`

**Purpose**: Abilities that players actively trigger through commands

**Base Class**: `lib/modules/research/activeResearchItem.c`

**Key Characteristics**:
- Requires player command to use
- Has resource costs (spell points, stamina, hit points)
- May have cooldown periods
- Defined by scope (who/what it affects)
- Can have damage/healing formulas

**Specialized Variants**:

#### Instantaneous Active
- **File**: `instantaneousActiveResearchItem.c`
- **Inherits**: `activeResearchItem.c` + `instantaneousEffect.c`
- **Purpose**: Most common type - provides immediate one-time effects
- **Examples**: Combat spells, healing abilities, instant buffs/debuffs
- **Effects**: Damage, healing, stat modifications, condition application

#### Persisted Active
- **File**: `persistedActiveResearchItem.c`
- **Inherits**: `activeResearchItem.c`
- **Purpose**: Creates persistent effects in the game world
- **Examples**: Magical barriers, area enchantments, persistent summons
- **Duration**: Has a duration specification for how long effects last

#### Instantaneous Persisted Active
- **File**: `instantaneousPersistedActiveResearchItem.c`
- **Inherits**: `persistedActiveResearchItem.c` + `instantaneousEffect.c`
- **Purpose**: Combines immediate effect with lasting world effects
- **Examples**: Explosive trap (instant damage + persistent hazard)

#### Combined Instantaneous Active
- **File**: `combinedInstantaneousActiveResearchItem.c`
- **Inherits**: `activeResearchItem.c` + `combinedInstantaneousEffect.c`
- **Purpose**: Chain multiple abilities together in combat combos
- **Examples**: Fighter attack combinations, spell combos
- **Features**:
  - Combination rules define what can be chained
  - Maximum chain length
  - Total cost is sum of all abilities in chain
  - Damage/effects stack based on combination

#### Composite Active
- **File**: `compositeActiveResearchItem.c`
- **Inherits**: `activeResearchItem.c` + `effectModifier.c`
- **Purpose**: Pre-built ability compositions like songs or sequences
- **Examples**: Bard songs with verse-chorus-bridge structure
- **Features**:
  - Uses composite templates to define structure
  - Players create and save named compositions
  - Executes segments in sequence
  - Used extensively by bard guild

#### Summoning
- **File**: `summoningResearchItem.c`
- **Inherits**: `activeResearchItem.c`
- **Purpose**: Summons creatures or companions
- **Features**:
  - Summons creatures based on persona type
  - Can specify level, equipment, modifiers
  - Summoned creatures join player's party
  - Can limit maximum number simultaneously summoned

### 2. Passive Research

**Type**: `"passive"`

**Purpose**: Permanent bonuses that are always active once learned

**Base Class**: `lib/modules/research/passiveResearchItem.c`

**Key Characteristics**:
- No activation required
- No resource cost
- Always active once researched
- Cannot be toggled off
- Provides permanent bonuses

**What Passive Research Can Provide**:
- Attribute bonuses (strength, intelligence, etc.)
- Skill bonuses (weapon skills, magic skills, etc.)
- Combat bonuses (attack, defense, damage, armor class)
- Resistance bonuses (fire resistance, poison resistance, etc.)
- Extra attacks per round
- Hit point/spell point/stamina maximums

**Examples**:
- +2 to Strength
- +10 to Long Sword skill
- +20% Fire Resistance
- +5 Damage with all attacks
- +1 weapon attack per round

### 3. Sustained Research

**Type**: `"sustained"`

**Purpose**: Toggle-able effects that remain active while maintained

**Base Class**: `lib/modules/research/sustainedResearchItem.c`

**Inherits**: `researchItem.c` + `effectModifier.c`

**Key Characteristics**:
- Must be activated (like active research)
- Remains active until deactivated or user runs out of resources
- Has initial activation cost (not consumed, but must have resources available)
- Reduces maximum resource pools while active
- Can be toggled on/off with same command
- Provides bonuses only while active

**Resource Cost Mechanics**:
- **Initial cost**: Must have this amount available to activate (not consumed)
- **Sustained cost**: Reduces maximum HP/SP/Stamina while active
- If current resources drop below sustained cost, automatically deactivates

**What Sustained Research Can Provide**:
- All passive-style bonuses (but only while active)
- Trait application (positive or negative)
- Modifiers that affect target(s)

**Scopes for Sustained**:
- `self` - Toggle personal buff on/off
- `targeted` - Apply sustained effect to a single target
- `area` - Apply sustained effect to all valid targets in room

**Examples**:
- Mage armor (sustained defensive buff)
- Haste (sustained speed enhancement)
- Protective aura (sustained area buff)
- Curse (sustained debuff on target)

### 4. Ritual Research

**Type**: `"ritual"`

**Purpose**: Complex abilities requiring preparation and components

**Base Class**: `lib/modules/research/ritualResearchItem.c`

**Key Characteristics**:
- More powerful than standard active abilities
- Requires consumable components
- May require specific locations or conditions
- Often has longer cooldowns
- No resource costs (but components are consumed)

**Specialized Variants**:

#### Instantaneous Ritual
- **File**: `instantaneousRitualResearchItem.c`
- **Inherits**: `ritualResearchItem.c` + `instantaneousEffect.c`
- **Purpose**: Rituals with immediate effects
- **Examples**: Blessing rituals, curse rituals

#### Persisted Ritual
- **File**: `persistedRitualResearchItem.c`
- **Inherits**: `ritualResearchItem.c`
- **Purpose**: Rituals that create lasting world effects
- **Examples**: Protective circles, warded areas, sanctified ground

### 5. Knowledge Research

**Type**: `"knowledge"`

**Purpose**: Represents learned lore, education, and theoretical knowledge

**Base Class**: `lib/modules/research/knowledgeResearchItem.c`

**Key Characteristics**:
- No activation or usage
- Serves as prerequisite for other research
- Often unlocks research trees
- Represents education and understanding

**Default Settings**:
- Automatically sets `scope` to `"self"`
- Automatically sets `effect` to `"strategic"`

**Special Features**:
- **Related Research**: Other research items can reference knowledge research to gain bonuses
- **Tree Roots**: Often used as the root of research trees
- **Equivalence**: Can have equivalent knowledge from different sources

**Examples**:
- Arcane Theory (prerequisite for spell research)
- Ancient Lore (unlocks historical knowledge tree)
- Sword Mastery Theory (provides understanding bonus to blade techniques)

### 6. Constructed Research

**Type**: `"constructed"`

**Purpose**: Modular component system for building custom abilities

**Components**: Forms + Functions + Effects

**Base Classes**:
- **Root**: `constructedActiveResearchItem.c` - Defines the construction system
- **Component**: `constructedResearchComponent.c` - Individual buildable pieces

**Component Types**:

#### Forms (Delivery Methods)
Define how the spell is delivered:
- `bolt` - Single target projectile
- `ball` - Area effect sphere
- `blast` - Cone effect
- `wave` - Line effect
- `wall` - Barrier
- `mist` - Area cloud
- `touch` - Melee range
- `arc` - Chain between targets

#### Functions (Damage/Effect Types)
Define what element or effect:
- `fire` - Fire damage
- `ice` - Cold damage
- `lightning` - Electrical damage
- `air` - Wind/air effects
- `vacuum` - Void effects

#### Effects (Modifiers)
Modify the constructed spell:
- `enhance damage` - Increases damage
- `reduce cost` - Decreases resource cost
- `siphon hp/sp/stamina` - Drains from target
- `damage hp/sp/stamina` - Additional resource damage
- `reduce/enhance attack/defense/soak` - Combat modifiers

**Construction Rules**:

Valid rule types:
- `function must include only one of` - Exactly one required
- `form must include only one of` - Exactly one required
- `effect must include only one of` - Exactly one required
- `effect can include only one of` - Zero or one allowed
- `effect can include any of` - Any number allowed

**Usage Examples**:

```
construct fire bolt at enemy
construct ice ball with enhance damage
construct lightning blast with reduce cost with siphon hp
```

**Cost Calculation**:

Total cost = base cost + sum of all component costs

### 7. Domain Research

**Type**: `"domain"`

**Purpose**: Territory and domain management abilities

**Base Class**: `lib/modules/domains/domainResearchItem.c`

**Key Characteristics**:
- Tied to domain/territory ownership
- Regional scope
- Domain management and enhancement

**Note**: Domain research is a specialized system primarily used for territory management features.

---

## Prerequisites

Prerequisites determine whether a character can LEARN a research item. They are checked before allowing research to be initiated.

**Defined in**: `lib/core/prerequisites.c`

### Valid Prerequisite Types

| Type | Description | Example |
|------|-------------|---------|
| `level` | Minimum character or guild level | Level 10, Level 5 in fighter guild |
| `skill` | Minimum skill value | Long sword 25 |
| `attribute` | Minimum attribute value | Strength 18 |
| `research` | Must have researched another item | Must know "fireball" |
| `quest` | Must have completed a quest | "Retrieve the Ancient Tome" |
| `guild` | Must be member of guild(s) | Member of mage or sorcerer |
| `guild rank` | Must have specific rank in guild | "Archmage" in mage guild |
| `race` | Must be of specific race(s) | Elf or half-elf |
| `faction` | Must be member of faction | Member of the Mages' Conclave |
| `trait` | Must have specific trait | Has "scholarly" or "magical affinity" |
| `background` | Must have background | Has "Noble" background |
| `combat statistic` | Combat achievements | Best kill level 45, Orc kills 100 |
| `opinion` | NPC opinion level | NPC opinion ? 50 |
| `state` | Conversation/quest state | Has discussed topic with NPC |
| `presence` | Object/character present | Requires altar present |
| `not present` | Object/character absent | Requires no witnesses |
| `spoken topics` | Has discussed topics | Has spoken about "ancient magic" |

### Adding Prerequisites

```
addSpecification("prerequisites", ([
    "long sword": ([
        "type": "skill",
        "value": 10
    ]),
    "/path/to/previous/research.c": ([
        "type": "research"
    ]),
    "intelligence": ([
        "type": "attribute",
        "value": 15
    ]),
    "level": ([
        "type": "level",
        "guild": "mage",  // optional - if omitted, uses effective level
        "value": 5
    ]),
    "some quest": ([
        "type": "quest"
    ]),
    "guild": ([
        "type": "guild",
        "value": ({ "mage", "sorcerer" })  // member of any listed
    ]),
    "elf": ([
        "type": "race",
        "value": ({ "elf", "half elf" })
    ]),
    "best kill": ([
        "type": "combat statistic",
        "value": 20  // best kill must be level 20+
    ])
]));
```

### Research Tree Prerequisites

Research trees add **parent-child prerequisites** automatically:
- To research a child, you must have researched all its parents
- Tree prerequisites are in addition to any item-specific prerequisites
- Checked via `researchTree->prerequisitesMetFor(item, character)`

---

## Limiters

Limiters determine whether a character can USE a research item after it's learned. They're checked each time the ability is used.

**Defined in**: `lib/core/specification.c` and `lib/services/limitor.c`

### Valid Limiter Types

| Type | Description | Values |
|------|-------------|--------|
| `opponent race` | Target must be specific race | Race name or array of races |
| `opponent guild` | Target must be from guild | Guild name or array of guilds |
| `opponent faction` | Target must be from faction | Faction path |
| `race` | User must be specific race | Race name or array of races |
| `guild` | User must be guild member | Guild name or array of guilds |
| `faction` | User must be faction member | Faction path |
| `crafting type` | Crafting type requirement | Crafting type name |
| `time of day` | Must be specific time | "morning", "afternoon", "evening", "night" |
| `season` | Must be specific season | "spring", "summer", "autumn", "winter" |
| `moon phase` | Must be specific moon phase | Moon phase name |
| `environment` | Must be in environment type | Environment type or array of types |
| `environment state` | Environment condition | State name or array of states |
| `intoxicated` | Must be intoxicated | Any value |
| `drugged` | Must be drugged | Any value |
| `near death` | Must be below HP threshold | 0-100 (percentage) |
| `stamina drained` | Must be below stamina threshold | 0-100 (percentage) |
| `spell points drained` | Must be below SP threshold | 0-100 (percentage) |
| `equipment` | Must be using equipment | Equipment name or array of equipment |
| `attribute` | Minimum attribute requirement | Mapping of attribute: value |
| `skill` | Minimum skill requirement | Mapping of skill: value |
| `quests` | Must have completed quests | Array of quest paths |
| `research` | Must have any of these research | Array of research paths |
| `research active` | Must have research active | Array of research paths (sustained) |
| `traits` | Must have any of these traits | Array of trait paths |

### Adding Limiters

```
addSpecification("limited by", ([
    "time of day": "night",
    "environment": ({ "forest", "plains" }),
    "weather": "clear",
    "season": "winter",
    "intoxicated": 1,
    "near death": 25,  // below 25% HP
    "skill": ([
        "long sword": 50
    ]),
    "research active": ({
        "/path/to/sustained/buff.c"
    })
]));
```

### Prerequisites vs Limiters Summary

**PREREQUISITES (learn-time checks)**:
- Can you START learning this research?
- Checked once when initiating research
- Examples: level, skills, completed quests, race, guild membership

**LIMITERS (use-time checks)**:
- Can you USE this ability RIGHT NOW?
- Checked every time ability is used
- Examples: time of day, weather, location, combat status

---

## Research Trees

Research trees organize related research in hierarchical structures with parent-child relationships.

**Defined in**: `lib/modules/research/researchTree.c`

### Tree Structure

```
Tree Root (often knowledge research)
+- First Tier Research
|  +- Second Tier Branch A
|  |  +- Advanced Research A
|  +- Second Tier Branch B
+- First Tier Alternative
   +- Advanced Research B
```

### Creating a Research Tree

```
// In your tree file (e.g., /lib/instances/research/trees/mage-tree.c)
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("elemental magic");
    Description("This tree contains research for elemental magic.");
    Source("mage");
    
    // Add all research items to tree
    addResearchElement("/path/to/elemental-theory.c");
    addResearchElement("/path/to/fireball.c");
    addResearchElement("/path/to/greater-fireball.c");
    addResearchElement("/path/to/firestorm.c");
    
    // Define parent-child relationships
    addChild("/path/to/fireball.c", "/path/to/elemental-theory.c");
    addChild("/path/to/greater-fireball.c", "/path/to/fireball.c");
    addChild("/path/to/firestorm.c", "/path/to/greater-fireball.c");
    
    // Set the tree root
    TreeRoot("/path/to/elemental-theory.c");
}
```

### Tree Methods

| Method | Purpose |
|--------|---------|
| `Name(string)` | Set/get tree name |
| `Description(string)` | Set/get tree description |
| `Source(string)` | Set/get source (usually guild name) |
| `TreeRoot(string)` | Set/get the root research item path |
| `addResearchElement(string)` | Add research item to tree |
| `addChild(child, parent)` | Create parent-child relationship |
| `prerequisitesMetFor(item, character)` | Check if character can research item |
| `getResearchTree(character)` | Get full tree structure |
| `getFlattenedResearchTree(character)` | Get flat list with status info |

### Tree Prerequisites

Tree prerequisites are automatically enforced:
1. Character must meet all item-specific prerequisites
2. Character must meet all tree-level prerequisites
3. Character must have researched all parent items

### Tree Root Special Properties

The tree root (usually knowledge research):
- Often has `"research type": "tree root"`
- May unlock access to entire tree
- Serves as entry point prerequisite
- Usually represents theoretical foundation

---

## Learning Types

Defines HOW a research item is acquired.

### 1. Points-Based

**Research Type**: `"points"`

Character spends research points to learn.

```
addSpecification("research type", "points");
addSpecification("research cost", 2);  // costs 2 research points
```

**Acquisition**:
- Characters earn research points through gameplay (levels, quests, achievements)
- Player chooses when to spend points
- Instantaneous learning

### 2. Time-Based

**Research Type**: `"timed"`

Learning occurs over real-world time.

```
addSpecification("research type", "timed");
addSpecification("research cost", 86400);  // 24 hours in seconds
```

**Acquisition**:
- Character initiates learning
- Must wait specified real-world time
- Can only study one timed research at a time
- Learning completes even if offline

**Time Conversion**:
- 60 seconds = 1 minute
- 3600 seconds = 1 hour  
- 86400 seconds = 1 day
- 604800 seconds = 1 week

### 3. Granted

**Research Type**: `"granted"`

Automatically learned when prerequisites are met.

```
addSpecification("research type", "granted");
```

**Acquisition**:
- No cost
- No player action required
- Automatically granted when all prerequisites satisfied
- Often used for quest rewards or story progression

### 4. Tree Root

**Research Type**: `"tree root"`

Special learning type for research tree roots.

```
addSpecification("research type", "tree root");
```

**Acquisition**:
- May unlock entire tree
- Often granted automatically or learned via quest
- Represents foundational knowledge

---

## Common Specifications

All research types share these fundamental specifications.

### Required for All Research

```
addSpecification("name", "fireball");
addSpecification("description", "A ball of roaring flames erupts from your hands.");
addSpecification("type", "active");  // or passive, sustained, ritual, knowledge, constructed, domain
addSpecification("research type", "points");  // or timed, granted, tree root
```

### Common Optional Specifications

```
// Learning cost (required if research type is "points" or "timed")
addSpecification("research cost", 2);

// Organization and categorization
addSpecification("source", "mage");  // Usually guild or origin
addSpecification("scope", "targeted");  // self, targeted, area, environmental, region, global
addSpecification("effect", "combat");  // beneficial, combat, enchantment, summoning, strategic

// Alternative/equivalent research
addSpecification("equivalence", "/path/to/equivalent/research.c");

// Help text for commands
addSpecification("usage summary", "fireball at <target>");
```

### Scope Values

| Scope | Affects |
|-------|---------|
| `self` | Only the user |
| `targeted` | A single chosen target |
| `area` | All valid targets in the room |
| `environmental` | The room/environment itself |
| `region` | An entire region |
| `global` | Global game-wide effects |
| `domain` | Domain/territory specific |

### Effect Values

| Effect | Purpose |
|--------|---------|
| `beneficial` | Helpful effects (healing, buffs, utilities) |
| `combat` | Combat-related (damage, debuffs, attacks) |
| `enchantment` | Enchantments and magical modifications |
| `summoning` | Summoning creatures or objects |
| `strategic` | Strategic/utility effects, knowledge |

---

## Research Enhancement Systems

The research system provides two distinct mechanisms for research items to reference and enhance other research: **Related Research** and **Affected Research**. Understanding the difference between these is critical for proper implementation.

### Related Research vs Affected Research

| Feature | Related Research | Affected Research |
|---------|-----------------|-------------------|
| **Used By** | Knowledge research only | Any research type (typically passive) |
| **Purpose** | Documents theoretical connections | Provides actual mechanical modifications |
| **Effect** | Display only - informational | Active gameplay effect - modifies damage, cost, cooldown, or combo chains |
| **Direction** | Defined ON the knowledge item | Defined ON the modifying research |
| **Syntax** | Array of file paths | Mapping of display names to numeric values |
| **Display Location** | Shows in related research details | Shows in the modifying research's details |

### Related Research (Knowledge Research)

**Purpose**: Documents which research items have theoretical connections to knowledge. This is purely informational and appears in research details but provides no mechanical benefit.

**Specification**: `"related research"`

**Valid For**: Knowledge research items only

**Syntax**:

```
addSpecification("related research", ({
    "/path/to/related/ability1.c",
    "/path/to/related/ability2.c",
    "/path/to/related/ability3.c"
});
```

**How It Works**:
- Define this specification on knowledge research
- Lists file paths of related research items
- When players examine the knowledge or related research, the connection is shown
- No mechanical effect - purely for documentation and immersion

**Example**:

```
// File: /guilds/mage/air/root.c
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addSpecification("name", "elemental air");
    addSpecification("description", "You have studied the theoretical "
        "foundations of air magic.");
    addSpecification("source", "mage");
    addSpecification("research type", "tree root");
    
    // Document theoretical connections (display only)
    addSpecification("related research", ({
        "/guilds/mage/air/gust.c",
        "/guilds/mage/air/wind-barrier.c",
        "/guilds/mage/air/cyclone.c"
    }));
}
```

When a player examines "gust", they'll see that "elemental air" knowledge is related, but there's no mechanical bonus.

### Affected Research (Mechanical Modifications)

**Purpose**: Provides actual mechanical modifications to other research items. This system allows one research item (typically passive) to enhance the damage, reduce costs, modify cooldowns, or extend combo chains of other abilities.

**Specifications**: Two specifications work together:
1. `"affected research"` - Mapping of research display names to numeric values
2. `"affected research type"` - Defines how those values are applied

**Valid For**: Any research type, but most commonly used in passive research

#### Affected Research Type Values

| Type | Purpose | Value Meaning | Applied To |
|------|---------|---------------|------------|
| `"percentage"` | Percentage-based enhancement | Percentage increase to damage/effect | Active abilities with damage formulas |
| `"bonus"` | Flat numeric addition | Direct numeric bonus | Active abilities with numeric values |
| `"max combination chain"` | Extend combo chains | Number of additional combo slots | Combined instantaneous research |
| `"decrease cost"` | Reduce resource costs | Amount subtracted from SP/HP/Stamina cost | Active abilities with resource costs |
| `"decrease cooldown"` | Reduce cooldown time | Seconds subtracted from cooldown | Active abilities with cooldowns |
| `"composite"` | Composite modifications | Special composite handling | Composite research |

#### Syntax

```
addSpecification("affected research type", "<type>");
addSpecification("affected research", ([
    "<research display name>": <numeric value>,
    "<another display name>": <numeric value>
]));
```

**Critical**: The keys in `"affected research"` must be the **display names** (from the `"name"` specification) of the target research, NOT file paths.

#### Display Format

When a player examines research that uses "affected research", they see:

**For `"percentage"`**:
```
This research enhances 'fireball' by +15%
This research enhances 'ice bolt' by +20%
```

**For `"bonus"`**:
```
This research enhances 'lightning strike' by +10
```

**For `"max combination chain"`**:
```
This increases the 'whirlwind combination' maximum combo chain size by +2
```

**For `"decrease cost"`**:
```
This reduces the cost to use 'fireball' by 10
```

**For `"decrease cooldown"`**:
```
This reduces the cooldown delay to use 'teleport' by 15
```

### Affected Research Examples

#### Example 1: Percentage Damage Enhancement

Passive research that increases damage of specific spells by percentage:

```
// File: /guilds/mage/passive/pyromancy-mastery.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "pyromancy mastery");
    addSpecification("description", "Your deep understanding of fire magic "
        "significantly increases the damage of your fire-based spells.");
    addSpecification("source", "mage");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    
    // Enhance fire spells by percentage
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "fireball": 15,           // +15% damage to fireball
        "flame strike": 15,       // +15% damage to flame strike  
        "immolation": 20,         // +20% damage to immolation
        "meteor swarm": 25        // +25% damage to meteor swarm
    ]));
    
    addSpecification("prerequisites", ([
        "elemental fire": ([
            "type": "skill",
            "value": 25
        ])
    ]));
}
```

#### Example 2: Flat Bonus Enhancement

Passive that adds flat damage to multiple elemental spells:

```
// File: /guilds/mage/passive/elemental-focus.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "elemental focus");
    addSpecification("description", "Your concentrated elemental energy adds "
        "raw power to your elemental attacks.");
    addSpecification("source", "mage");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    
    // Add flat bonus damage
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "fireball": 10,
        "ice bolt": 10,
        "lightning": 10,
        "acid spray": 10
    ]));
}
```

#### Example 3: Extend Combination Chains

Passive that allows longer combat combos:

```
// File: /guilds/fighter/passive/combo-mastery.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "combo mastery");
    addSpecification("description", "Your combat expertise allows you to "
        "chain additional attacks in your combinations.");
    addSpecification("source", "fighter");
    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    
    // Increase max combo chain length
    addSpecification("affected research type", "max combination chain");
    addSpecification("affected research", ([
        "whirlwind combination": 2,     // +2 attacks in combo
        "blade dance": 2,                // +2 attacks in combo
        "devastating assault": 3         // +3 attacks in combo
    ]));
    
    addSpecification("prerequisites", ([
        "level": ([
            "type": "level",
            "guild": "fighter",
            "value": 15
        ])
    ]));
}
```

#### Example 4: Reduce Resource Costs

Passive that makes abilities cheaper to use:

```
// File: /guilds/mage/passive/spell-efficiency.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "spell efficiency");
    addSpecification("description", "Your refined understanding of magical "
        "theory allows you to cast spells with greater efficiency.");
    addSpecification("source", "mage");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    
    // Reduce spell point costs
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "fireball": 10,            // -10 SP
        "ice bolt": 10,            // -10 SP
        "lightning": 15,           // -15 SP
        "meteor swarm": 25,        // -25 SP
        "time stop": 50            // -50 SP
    ]));
    
    addSpecification("bonus spellcraft", 10);
    
    addSpecification("prerequisites", ([
        "spellcraft": ([
            "type": "skill",
            "value": 20
        ])
    ]));
}
```

#### Example 5: Reduce Cooldowns

Passive that reduces ability cooldowns:

```
// File: /guilds/mage/passive/quickcast.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "quickcast");
    addSpecification("description", "Your practiced casting techniques allow "
        "you to use your abilities more frequently.");
    addSpecification("source", "mage");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    
    // Reduce cooldown times (in seconds)
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "fireball": 10,            // -10 seconds
        "ice bolt": 10,            // -10 seconds
        "teleport": 30,            // -30 seconds
        "dimension door": 45,      // -45 seconds
        "time stop": 60            // -60 seconds
    ]));
    
    addSpecification("prerequisites", ([
        "level": ([
            "type": "level",
            "guild": "mage",
            "value": 12
        ])
    ]));
}
```

#### Example 6: Multiple Abilities Enhanced

A single passive affecting many related abilities:

```
// File: /guilds/fighter/passive/weapon-mastery.c
inherit "/lib/modules/research/passiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "weapon mastery");
    addSpecification("description", "Your complete mastery of weapons "
        "significantly enhances all of your weapon techniques.");
    addSpecification("source", "fighter");
    addSpecification("research type", "points");
    addSpecification("research cost", 5);
    
    // Percentage boost to many weapon techniques
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "slash": 20,
        "thrust": 20,
        "cleave": 20,
        "riposte": 20,
        "whirlwind": 25,
        "blade dance": 25,
        "devastating blow": 30,
        "master stroke": 30,
        "chop": 20,
        "hack": 20,
        "thrash": 25
    ]));
    
    addSpecification("prerequisites", ([
        "level": ([
            "type": "level",
            "guild": "fighter",
            "value": 20
        ])
    ]));
}
```

### Design Guidelines

#### When to Use Related Research

- Knowledge research documenting theoretical foundations
- Purely informational/educational purposes
- No mechanical effect needed
- Shows thematic connections between knowledge and abilities
- Define ON the knowledge item, pointing TO the abilities (using file paths)

#### When to Use Affected Research

- Passive research providing mechanical enhancements
- Active modifications to damage, cost, cooldown, or combo chains
- Specialization or mastery bonuses
- Define ON the modifying research, pointing TO the abilities being modified (using display names)

#### Common Patterns

**Specialization Passives**: Percentage damage bonuses for specific ability schools

```
addSpecification("affected research type", "percentage");
addSpecification("affected research", ([
    "fire spell name": 15,
    "another fire spell": 15
]));
```

**Efficiency Passives**: Cost reduction for resource management

```
addSpecification("affected research type", "decrease cost");
addSpecification("affected research", ([
    "expensive spell": 25,
    "another spell": 15
]));
```

**Speed Passives**: Cooldown reduction for faster ability usage

```
addSpecification("affected research type", "decrease cooldown");
addSpecification("affected research", ([
    "teleport": 30,
    "blink": 15
]));
```

**Mastery Passives**: Flat bonuses to groups of related abilities

```
addSpecification("affected research type", "bonus");
addSpecification("affected research", ([
    "basic attack": 10,
    "power attack": 15
]));
```

**Advanced Combat Passives**: Combo chain extensions

```
addSpecification("affected research type", "max combination chain");
addSpecification("affected research", ([
    "whirlwind combo": 2
]));
```

### Key Differences Summary

**RELATED RESEARCH (Knowledge - Display Only)**
- Defined ON knowledge research
- Points TO abilities using FILE PATHS
- No mechanical effect

```
addSpecification("related research", ({
    "/full/path/to/ability.c",
    "/full/path/to/another.c"
}));
```

**AFFECTED RESEARCH (Any Type - Mechanical Effect)**
- Defined ON modifying research
- References abilities by DISPLAY NAMES
- Actual gameplay effect

```
addSpecification("affected research type", "percentage");  // or bonus, decrease cost, etc.
addSpecification("affected research", ([
    "ability display name": 15,  // NOT file paths
    "another ability name": 20
]));
```

### Important Notes

1. **Display Names vs File Paths**: 
   - Related research uses file paths: `"/path/to/file.c"`
   - Affected research uses display names: `"fireball"` (from the ability's `"name"` specification)

2. **Case Sensitivity**: Display names in affected research must match exactly (case-sensitive)

3. **Multiple Modifiers**: An ability can be affected by multiple passive research items - effects stack

4. **No Self-Reference**: Research cannot affect itself

5. **Type Consistency**: Use the appropriate affected research type for the modification you want:
   - Damage scaling: `"percentage"` or `"bonus"`
   - Resource efficiency: `"decrease cost"`
   - Usage frequency: `"decrease cooldown"`
   - Combo depth: `"max combination chain"`