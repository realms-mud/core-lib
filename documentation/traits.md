# traits.md

#### Traits System Overview

Traits in this MUD represent a sophisticated character development system that 
encompasses everything from personality characteristics to temporary magical
effects. The system provides deep character customization through permanent traits,
temporary effects, and research-based enhancements that fundamentally alter 
character abilities, skills, behaviors, and interactions with the world.

The traits system operates on multiple interconnected levels:
1. **Permanent Traits**: Long-lasting character characteristics that define who the character is
2. **Temporary Traits**: Time-limited effects from spells, potions, diseases, or environmental conditions
3. **Sustained Traits**: Effects maintained by active research or magical practices
4. **Research Integration**: Traits that unlock research trees or are granted by research completion
5. **Combat Integration**: Traits that directly affect combat calculations and abilities
6. **Social Integration**: Traits that influence NPC interactions and faction relationships

##### Traits Inheritance Hierarchy

All traits inherit from a base trait class that provides comprehensive validation and functionality:

~~~c
inherit "/lib/modules/traits/baseTrait.c";
~~~

This base class provides:
- **Trait validation**: Ensures all required properties are properly set and valid
- **Bonus system**: Manages complex stat bonuses, penalties, and modifiers
- **Prerequisites system**: Handles requirements for trait acquisition including race, research, and other traits
- **Research integration**: Links traits to research trees and sustained effects
- **Combat integration**: Provides extra attacks, damage bonuses, and special abilities
- **Display system**: Formats trait information for player viewing

##### System File Locations

The traits system is extensively organized across multiple directories and files:

###### Core System Files
- **lib/modules/traits/baseTrait.c** - Base trait functionality and validation
- **lib/modules/traits.c** - Character trait management, addition, removal, and queries
- **lib/modules/secure/traits.h** - Trait data structures and persistence
- **lib/services/traitsService.c** - Trait service, lookup, and caching system

###### Trait Categories and Instances
- **lib/instances/traits/health/** - Physical health conditions, wellness, and medical states
- **lib/instances/traits/educational/** - Learned skills, academic knowledge, and professional training
- **lib/instances/traits/personality/** - Character personality traits, behavioral patterns, and mental characteristics
- **lib/instances/traits/genetic/** - Inherited characteristics, physical appearance, and genetic predispositions
- **lib/instances/traits/professional/** - Career-specific skills, occupational abilities, and trade expertise
- **lib/instances/traits/guild/** - Guild-specific traits, memberships, and organizational benefits
- **lib/instances/traits/role/** - Social roles, positions, and organizational standings
- **lib/instances/traits/effects/** - Temporary magical effects, spell consequences, and transient states
- **lib/instances/traits/background/** - Cultural background, regional origins, and historical context
- **lib/instances/traits/racial/** - Race-specific traits, abilities, and inherent characteristics
- **lib/instances/traits/biological/** - Biological processes, body chemistry, and physiological states
- **lib/instances/traits/archetypes/** - Personality archetypes and psychological profiles
- **lib/instances/traits/eyes/** - Physical appearance traits for eye color and characteristics

###### Integration Points
- **lib/modules/combat.c** - Combat system integration for bonuses and special abilities
- **lib/modules/research.c** - Research system integration for unlocking and sustaining traits
- **lib/services/bonusesService.c** - Validation of all bonus types and modifiers
- **lib/core/prerequisites.c** - Prerequisite system for trait acquisition requirements

##### Trait Types and Classifications

The system supports multiple trait types as defined in **lib/services/traitsService.c**:

~~~c
private string *validTraitTypes = ({ "health", "educational", "personality", 
    "genetic", "professional", "guild", "role", "effect", "sustained effect",
    "background", "racial", "persona" });
~~~

###### Permanent Trait Types

**Health Traits**
Physical health conditions, wellness states, and medical characteristics 
that affect a character's constitution, hit points, and resistance to 
disease and injury.

**Educational Traits**
Learned skills, academic knowledge, formal training, and intellectual a
chievements that provide bonuses to relevant skills and knowledge areas.

**Personality Traits**
Character personality characteristics, behavioral patterns, mental 
dispositions, and psychological traits that affect social interactions 
and decision-making.

**Genetic Traits**
Inherited characteristics, physical appearance, genetic predispositions,
and biological features that are determined at birth or through heredity.

**Professional Traits**
Career-related abilities, occupational skills, trade expertise, and 
professional training that provide bonuses to work-related activities.

**Guild Traits**
Guild membership benefits, organizational abilities, group affiliations,
and special privileges granted through guild membership.

**Role Traits**
Social roles, positions of authority, organizational standings, and 
responsibility-based traits that affect interactions and capabilities.

**Background Traits**
Cultural background, regional origins, historical context, and environmental 
influences that shape character development and worldview.

**Racial Traits**
Race-specific characteristics, inherent abilities, biological features, 
and cultural traits that are tied to the character's racial heritage.

**Persona Traits**
Personality archetypes, psychological profiles, and comprehensive character 
patterns that encompass multiple aspects of personality.

###### Temporary Trait Types

**Effect Traits**
Time-limited effects with specific duration, typically from spells, 
potions, diseases, or environmental conditions that modify character 
abilities temporarily.

**Sustained Effect Traits**
Effects maintained by active research, magical practices, or ongoing 
activities that last as long as the sustaining condition remains active.

##### Creating Basic Traits

All traits must inherit from the base trait class and implement a Setup() 
method that defines the trait's properties:

~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "attractive");
    addSpecification("description", "You are naturally attractive and "
        "appealing to others. This gives you a bonus to charisma and "
        "makes social interactions easier.");
    addSpecification("type", "genetic");
    addSpecification("root", "attractive");
    addSpecification("bonus charisma", 2);
    addSpecification("cost", 2);
    addSpecification("opinion", 5);
}
~~~

##### Required Trait Properties

Every trait must define these essential properties for proper system integration:

###### Absolutely Required Properties
- **name**: The trait's display name (string) - how it appears to players
- **description**: Detailed description of the trait's effects and significance (string)
- **type**: Category of trait (string) - must be from validTraitTypes array
- **root**: Base trait family for grouping and conflict resolution (string)

###### Commonly Used Optional Properties
- **opposing root**: Conflicting trait family that cannot coexist (string)
- **cost**: Point cost for trait acquisition in character creation (integer)
- **opinion**: Base NPC opinion modifier (integer)
- **opposing opinion**: Opinion modifier for characters with opposing traits (integer)
- **research tree**: Research tree unlocked by possessing this trait (string)
- **expire message**: Message displayed when temporary trait expires (string)
- **duration**: Duration in seconds for effect traits (integer)
- **triggering research**: Research that maintains sustained effect traits (string)

##### Comprehensive Trait Examples

###### Health Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "hale");
    addSpecification("description", "You are in excellent health and "
        "physical condition. Your robust constitution grants you extra "
        "hit points, faster healing, and resistance to disease. You "
        "recover from injuries more quickly and have greater stamina "
        "for physical activities.");
    addSpecification("type", "health");
    addSpecification("root", "hale");
    addSpecification("opposing root", "sickly");
    addSpecification("bonus constitution", 2);
    addSpecification("bonus hit points", 15);
    addSpecification("bonus heal hit points", 2);
    addSpecification("bonus resist disease", 20);
    addSpecification("opinion", 5);
    addSpecification("cost", 3);
}
~~~

###### Educational Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "tactician");
    addSpecification("description", "You have received extensive training "
        "in military tactics, battlefield strategy, and unit coordination. "
        "This education grants you bonuses to tactics, leadership, and "
        "intelligence. You can better analyze combat situations and "
        "coordinate group activities.");
    addSpecification("type", "educational");
    addSpecification("root", "military training");
    addSpecification("bonus tactics", 10);
    addSpecification("bonus leadership", 5);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus combat analysis", 8);
    addSpecification("opinion", 8);
    addSpecification("cost", 4);
}
~~~

###### Personality Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "abrasive");
    addSpecification("description", "You have a tendency to rub people "
        "the wrong way through blunt speech, tactless comments, and "
        "generally difficult behavior. While this hinders most social "
        "interactions, it also makes you more resistant to mental "
        "influences and intimidation attempts.");
    addSpecification("type", "personality");
    addSpecification("root", "abrasive");
    addSpecification("opposing root", "charming");
    addSpecification("penalty to charisma", 2);
    addSpecification("penalty to persuasion", 5);
    addSpecification("bonus resist mental", 5);
    addSpecification("bonus resist intimidation", 5);
    addSpecification("opinion", -10);
    addSpecification("opposing opinion", -15);
    addSpecification("cost", -1);
}
~~~

###### Genetic Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "attractive");
    addSpecification("description", "You are naturally attractive and "
        "physically appealing. This genetic gift grants you bonuses to "
        "charisma-based interactions, makes others more inclined to "
        "help you, and provides advantages in social situations.");
    addSpecification("type", "genetic");
    addSpecification("root", "attractive");
    addSpecification("opposing root", "unattractive");
    addSpecification("bonus charisma", 2);
    addSpecification("bonus persuasion", 3);
    addSpecification("bonus haggling", 2);
    addSpecification("opinion", 8);
    addSpecification("cost", 3);
}
~~~

###### Professional Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "master blacksmith");
    addSpecification("description", "You are a master craftsman in the "
        "art of blacksmithing. Years of training and experience grant "
        "you exceptional skill in working with metals, creating superior "
        "weapons and armor, and understanding the properties of different "
        "materials.");
    addSpecification("type", "professional");
    addSpecification("root", "master craftsman");
    addSpecification("bonus blacksmithing", 15);
    addSpecification("bonus weapon smithing", 10);
    addSpecification("bonus metal crafting", 8);
    addSpecification("bonus appraisal", 5);
    addSpecification("opinion", 10);
    addSpecification("cost", 5);
}
~~~

###### Background Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "noble");
    addSpecification("description", "You come from noble birth and high "
        "social standing. This background grants you knowledge of court "
        "etiquette, political maneuvering, and social graces. You have "
        "connections among the upper classes and are treated with "
        "respect by most NPCs.");
    addSpecification("type", "background");
    addSpecification("root", "noble");
    addSpecification("opposing root", "commoner");
    addSpecification("bonus etiquette", 10);
    addSpecification("bonus politics", 8);
    addSpecification("bonus persuasion", 5);
    addSpecification("bonus charisma", 1);
    addSpecification("opinion", 15);
    addSpecification("cost", 4);
}
~~~

###### Racial Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "deity touched elf");
    addSpecification("description", "You are an elf who has been touched "
        "by divine power. This blessing grants you enhanced magical "
        "abilities, resistance to evil influences, and a natural "
        "connection to divine magic. Your aura of holiness affects "
        "how others perceive you.");
    addSpecification("type", "racial");
    addSpecification("root", "deity touched");
    addSpecification("bonus magic", 8);
    addSpecification("bonus resist evil", 25);
    addSpecification("bonus spell points", 20);
    addSpecification("bonus divine magic", 10);
    addSpecification("opinion", 12);
    addSpecification("cost", 6);
}
~~~

###### Temporary Effect Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "ethereal");
    addSpecification("description", "You have been transformed into an "
        "ethereal state, making you immune to most physical attacks but "
        "vulnerable to magical ones. Your form is translucent and you "
        "can pass through some barriers, but magical forces affect you "
        "more strongly.");
    addSpecification("type", "effect");
    addSpecification("root", "ethereal");
    addSpecification("duration", 300);  // 5 minutes
    addSpecification("bonus resist physical", 95);
    addSpecification("penalty to resist magical", 25);
    addSpecification("bonus stealth", 10);
    addSpecification("expire message", "You feel yourself becoming solid again.");
}
~~~

###### Sustained Effect Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "enhanced strength");
    addSpecification("description", "Your strength is magically enhanced "
        "through sustained research and magical practice. This effect "
        "lasts as long as you maintain the research that grants it.");
    addSpecification("type", "sustained effect");
    addSpecification("root", "enhanced strength");
    addSpecification("triggering research", "/lib/instances/research/magic/enhance/strength.c");
    addSpecification("bonus strength", 4);
    addSpecification("bonus hit points", 20);
    addSpecification("bonus damage", 3);
}
~~~

###### Biological Trait Example
~~~c
inherit "/lib/modules/traits/baseTrait.c";

protected void Setup()
{
    addSpecification("name", "adrenaline");
    addSpecification("description", "Your body is experiencing an "
        "adrenaline rush, heightening your physical capabilities. "
        "You move faster, hit harder, and react more quickly, but "
        "this state cannot be maintained indefinitely.");
    addSpecification("type", "effect");
    addSpecification("root", "adrenaline");
    addSpecification("duration", 180);  // 3 minutes
    addSpecification("bonus strength", 3);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 4);
    addSpecification("expire message", "The adrenaline rush fades and you feel normal again.");
}
~~~

##### Comprehensive Stat Bonuses and Penalties

Traits can provide bonuses or penalties to virtually any game statistic 
through the bonus system:

###### Primary Attribute Bonuses
~~~c
addSpecification("bonus strength", 2);      // Physical power and damage
addSpecification("bonus dexterity", 1);     // Speed, accuracy, and reflexes
addSpecification("bonus constitution", 3);  // Health, stamina, and endurance
addSpecification("bonus intelligence", 1);  // Mental acuity and spell power
addSpecification("bonus wisdom", 2);        // Perception and magical resistance
addSpecification("bonus charisma", 1);      // Social skills and leadership
~~~

###### Primary Attribute Penalties
~~~c
addSpecification("penalty to strength", 1);     // Reduced physical power
addSpecification("penalty to dexterity", 2);    // Reduced speed and accuracy
addSpecification("penalty to constitution", 1); // Reduced health and stamina
addSpecification("penalty to intelligence", 1); // Reduced mental capacity
addSpecification("penalty to wisdom", 1);       // Reduced perception
addSpecification("penalty to charisma", 2);     // Reduced social appeal
~~~

###### Vital Statistics Bonuses
~~~c
addSpecification("bonus hit points", 25);       // Maximum health
addSpecification("bonus spell points", 15);     // Maximum magical energy
addSpecification("bonus stamina points", 20);   // Maximum physical energy
~~~

###### Combat Bonuses and Penalties
~~~c
addSpecification("bonus attack", 5);            // Attack accuracy
addSpecification("bonus defese", 3);            // Defensive ability
addSpecification("bonus damage", 2);            // Damage output
addSpecification("bonus armor class", 1);       // Damage reduction
addSpecification("bonus weapon class", 3);      // Weapon effectiveness
~~~

###### Skill Bonuses (Extensive Examples)
~~~c
// Combat Skills
addSpecification("bonus long sword", 10);       // Sword fighting
addSpecification("bonus dodge", 5);             // Avoiding attacks
addSpecification("bonus parry", 8);             // Deflecting attacks
addSpecification("bonus block", 6);             // Shield use

// Magic Skills
addSpecification("bonus magic", 8);             // General magical ability
addSpecification("bonus spellcraft", 10);       // Spell creation and theory
addSpecification("bonus elemental fire", 12);   // Fire magic
addSpecification("bonus body", 15);          // Healing magic

// Social Skills
addSpecification("bonus persuasion", 8);        // Convincing others
addSpecification("bonus intimidation", 6);      // Threatening others
addSpecification("bonus haggling", 4);          // Bargaining
addSpecification("bonus leadership", 10);       // Leading groups

// Crafting Skills
addSpecification("bonus blacksmithing", 15);    // Metalworking
addSpecification("bonus alchemy", 12);          // Potion making
addSpecification("bonus enchanting", 8);        // Magical enhancement

// Knowledge Skills
addSpecification("bonus lore", 10);             // General knowledge
addSpecification("bonus history", 8);           // Historical knowledge
addSpecification("bonus tactics", 12);          // Military strategy
~~~

###### Resistance Bonuses
~~~c
addSpecification("bonus resist fire", 20);      // Fire damage resistance
addSpecification("bonus resist cold", 15);      // Cold damage resistance
addSpecification("bonus resist mental", 25);    // Mental attack resistance
addSpecification("bonus resist poison", 30);    // Poison resistance
addSpecification("bonus resist disease", 25);   // Disease resistance
addSpecification("bonus resist magic", 20);     // General magic resistance
~~~

###### Healing and Recovery Bonuses
~~~c
addSpecification("bonus heal hit points", 3);         // Faster HP recovery
addSpecification("bonus heal spell points", 2);       // Faster SP recovery
addSpecification("bonus heal stamina", 2);            // Faster stamina recovery
addSpecification("bonus heal hit points rate", 2);    // More frequent HP healing
addSpecification("bonus heal spell points rate", 1);  // More frequent SP healing
addSpecification("bonus heal stamina rate", 1);       // More frequent stamina healing
~~~

##### Research System Integration

Traits integrate deeply with the research system in multiple ways:

###### Research Tree Unlocking
Some traits unlock entire research trees, providing access to new 
magical or professional abilities:

~~~c
addSpecification("research tree", "/lib/instances/research/magic/elemental/fire.c");
~~~

This grants access to fire elemental magic research when the trait is acquired.

###### Sustained Research Effects
Sustained traits are maintained by active research and disappear when
the research is deactivated:

~~~c
addSpecification("type", "sustained effect");
addSpecification("triggering research", "/lib/instances/research/magic/enhance/strength.c");
~~~

###### Research Prerequisites
Traits can require specific research to be completed before they can be acquired:

~~~c
addSpecification("research prerequisites", ([
    "/lib/instances/research/magic/basic/elementalism.c": 1,
    "/lib/instances/research/magic/fire/novice.c": 1
]));
~~~

##### Trait Interactions and Conflicts

###### Opposing Traits
Traits can define opposing trait families that create conflicts and cannot coexist:

~~~c
addSpecification("root", "brave");
addSpecification("opposing root", "cowardly");
~~~

Characters cannot have both brave and cowardly traits simultaneously.

###### Opinion Modifiers
Traits affect how NPCs react to characters, creating complex social dynamics:

~~~c
addSpecification("opinion", 15);           // Positive opinion modifier
addSpecification("opposing opinion", -10); // Negative for opposing traits
~~~

NPCs with the same trait root will like the character more, while 
those with opposing traits will like them less.

###### Trait Costs and Character Creation
Traits have point costs that balance their benefits during character creation:

~~~c
addSpecification("cost", 3);    // Positive cost (beneficial trait)
addSpecification("cost", -2);   // Negative cost (disadvantageous trait)
addSpecification("cost", 0);    // No cost (neutral trait)
~~~

##### Special Trait Abilities

###### Extra Attacks
Traits can provide additional attacks per combat round:

~~~c
addSpecification("bonus weapon attack", 1);     // Extra weapon attack
addSpecification("bonus fire attack", 15);      // Fire damage attack
addSpecification("bonus claw attack", 10);      // Natural weapon attack
~~~

###### Weapon Enchantments
Traits can enchant weapons with magical properties:

~~~c
addSpecification("enchantments", ([
    "fire": 10,      // Fire damage
    "magical": 5,    // Magical damage
    "holy": 8        // Holy damage
]));
~~~

###### Expire Messages
Temporary traits can display messages when they end:

~~~c
addSpecification("expire message", "The magical enhancement fades away.");
~~~

##### Trait Management and Lifecycle

###### Adding Traits
Traits are added through the character's trait service:

~~~c
// In character code
object traits = getModule("traits");
traits->addTrait("/lib/instances/traits/health/hale.c");
~~~

###### Removing Traits
Traits can be removed when appropriate:

~~~c
traits->removeTrait("/lib/instances/traits/health/hale.c");
~~~

###### Temporary Trait Application
Temporary traits are applied with duration:

~~~c
// Applied with 2-minute duration
traits->addTrait("/lib/instances/traits/effects/haste.c", 120);
~~~

###### Sustained Trait Management
Sustained traits are automatically managed by the research system:

~~~c
// Applied when research is active
// Removed when research is deactivated
// No manual management required
~~~

##### Trait Categories in Comprehensive Detail

###### Health Traits
Physical health and wellness characteristics that affect constitution, 
hit points, disease resistance, and recovery:

- **hale**: Excellent health providing constitution bonus, extra hit points, and disease resistance
- **sickly**: Poor health with constitution penalty, reduced hit points, and disease vulnerability
- **hardy**: Natural toughness with poison and disease resistance bonuses
- **frail**: Physical weakness with reduced hit points and increased vulnerability
- **robust**: Strong constitution with stamina bonuses and physical resistance
- **diseased**: Active disease state with multiple penalties and contagion risk

###### Educational Traits
Learned skills, academic knowledge, and professional training:

- **tactician**: Military tactics training with leadership and strategy bonuses
- **strategist**: Advanced strategic thinking with planning and analysis bonuses
- **architect**: Engineering and construction knowledge with building skill bonuses
- **scholar**: Academic learning with knowledge skill bonuses and research abilities
- **linguist**: Language mastery with communication and translation bonuses
- **historian**: Historical knowledge with lore and cultural understanding bonuses

###### Personality Traits
Character personality characteristics and behavioral patterns:

- **abrasive**: Difficult personality with social penalties but mental resistance
- **charming**: Appealing personality with charisma bonuses and social advantages
- **brave**: Courage providing fear resistance and morale bonuses
- **cowardly**: Fear responses with combat penalties but survival instincts
- **patient**: Calm demeanor with meditation bonuses and stress resistance
- **impulsive**: Quick reactions with speed bonuses but judgment penalties

###### Genetic Traits
Inherited physical characteristics and genetic predispositions:

- **attractive**: Natural appeal with charisma bonuses and social advantages
- **blue eyes**: Specific eye color with potential magical affinities
- **tall**: Height advantage with reach bonuses and intimidation benefits
- **short**: Compact size with stealth bonuses and agility benefits
- **strong**: Natural strength with physical bonuses and carrying capacity
- **quick**: Natural speed with dexterity bonuses and reaction benefits

###### Professional Traits
Career and occupation-specific abilities:

- **warrior**: Combat training with weapon skill bonuses and tactical knowledge
- **mage**: Magical aptitude with spell point bonuses and magical skill benefits
- **thief**: Stealth and deception skills with criminal knowledge and agility
- **merchant**: Trading expertise with haggling bonuses and market knowledge
- **artisan**: Crafting mastery with creation skill bonuses and quality improvements
- **healer**: Medical knowledge with healing skill bonuses and diagnostic abilities

###### Background Traits
Cultural and historical background influences:

- **noble**: High social standing with etiquette bonuses and political connections
- **peasant**: Common origins with practical skills and survival knowledge
- **outlander**: Foreign background with unique perspectives and adaptability
- **city dweller**: Urban upbringing with social skills and street knowledge
- **tribal**: Primitive background with nature skills and spiritual connections
- **military**: Armed forces background with discipline and combat experience

###### Racial Traits
Race-specific characteristics and abilities:

- **deityTouchedElf**: Divine blessing with magical bonuses and holy resistance
- **elvensight**: Enhanced vision with perception bonuses and magical sight
- **dwarven resilience**: Natural toughness with poison resistance and endurance
- **human adaptability**: Versatility with skill bonuses and learning advantages
- **orcish fury**: Battle rage with combat bonuses and berserker abilities
- **halfling luck**: Natural fortune with saving throw bonuses and chance benefits

###### Effect Traits
Temporary magical effects and transient states:

- **ethereal**: Physical immunity with magical vulnerability and ghostly abilities
- **haste**: Increased speed with extra actions and movement bonuses
- **strength**: Temporary strength enhancement with damage and carrying bonuses
- **invisibility**: Concealment effects with stealth bonuses and surprise advantages
- **flight**: Aerial movement with positioning advantages and escape options
- **protection**: Magical shields with damage resistance and spell deflection

###### Biological Traits
Biological processes and physiological states:

- **adrenaline**: Heightened physical state with temporary combat bonuses
- **fatigue**: Exhaustion state with penalties to all physical activities
- **fever**: Illness state with constitution penalties and disorientation
- **regeneration**: Enhanced healing with accelerated recovery rates
- **metabolism**: Efficient energy use with reduced food requirements
- **circulation**: Improved blood flow with endurance and recovery bonuses

##### Integration with Combat System

Traits integrate extensively with **lib/modules/combat.c** to affect all aspects of combat:

###### Combat Calculations
- **Attack bonuses**: Modify calculateAttack() for accuracy improvements
- **Defense bonuses**: Modify calculateDefendAttack() for avoidance abilities
- **Damage bonuses**: Modify calculateDamage() for increased harm output
- **Resistance bonuses**: Modify calculateSoakDamage() for damage reduction
- **Healing bonuses**: Modify healing rates and recovery calculations

###### Extra Attacks Per Round
Traits can provide additional attacks during combat rounds:

~~~c
public nomask mapping *getExtraAttacks()
{
    return ({ 
        (["attack type": "claw", "damage": 15, "to hit": 60]),
        (["attack type": "bite", "damage": 10, "to hit": 55])
    });
}
~~~

###### Combat State Modifications
Traits can alter combat states and abilities:

~~~c
// Berserker rage trait
addSpecification("bonus damage", 8);
addSpecification("bonus attack", 5);
addSpecification("penalty to defend attack", 3);
addSpecification("duration", 120);
~~~

##### Character Creation Integration

Traits are deeply integrated into character creation systems:

###### Point-Based Selection
Players select traits during character creation based on balanced point costs:

~~~c
// Character creation interface
mapping traitOptions = getService("traits")->creationListForTraitType("personality");
~~~

###### Trait Validation and Conflicts
The system validates trait combinations and prevents conflicts:

~~~c
// Opposing traits cannot be selected together
// Prerequisites must be met
// Point costs must be within character creation limits
// Race restrictions are enforced
~~~

###### Trait Packages
Some character backgrounds provide trait packages:

~~~c
// Noble background might include:
// - Noble trait (+4 cost)
// - Educated trait (+2 cost)
// - Wealthy trait (+3 cost)
// - Soft Living trait (-2 cost)
// Net cost: +7 points
~~~

##### Trait Display and Information Systems

###### Detailed Trait Information
The system provides comprehensive trait information:

~~~c
string details = getService("traits")->traitDetails("hale");
~~~

This displays:
- Trait name and type
- Complete description
- All bonuses and penalties
- Prerequisites and requirements
- Research tree unlocks
- Opinion modifiers
- Cost information

###### Character Trait Listing
Characters can view their traits in organized categories:

~~~c
// In character sheet or traits command
string traitList = traits->traitsDisplay();
~~~

###### Trait Comparison
Players can compare traits during selection:

~~~c
// Compare multiple traits
mapping comparison = traits->compareTraits(({ "hale", "sickly", "hardy" }));
~~~

##### Advanced Trait Features and Mechanics

###### Conditional Traits
Traits can have complex acquisition conditions:

~~~c
// Only available to certain races
addSpecification("race prerequisites", ({ "elf", "half-elf" }));

// Only available with specific research
addSpecification("research prerequisites", ([
    "/lib/instances/research/magic/basic/elementalism.c": 1
]));

// Only available at certain levels
addSpecification("level prerequisites", 15);

// Only available with other traits
addSpecification("trait prerequisites", ({ "brave", "strong" }));
~~~

###### Scaling and Progressive Traits
Traits can improve with character advancement:

~~~c
// Bonus increases with level
addSpecification("scaling bonus", ([
    "attribute": "strength",
    "base": 1,
    "per level": 0.1,
    "maximum": 5
]));

// Bonus increases with skill
addSpecification("skill scaling", ([
    "skill": "long sword",
    "bonus": "weapon class",
    "ratio": 0.2
]));
~~~

###### Trait Synergies and Combinations
Some traits work better together:

~~~c
// Synergy bonuses
addSpecification("synergy traits", ([
    "tactician": (["bonus leadership": 2]),
    "strategist": (["bonus tactics": 3]),
    "military": (["bonus command": 5])
]));
~~~

###### Environmental Trait Effects
Traits can be affected by environment:

~~~c
// Bonuses in specific environments
addSpecification("environmental bonuses", ([
    "forest": (["bonus stealth": 5, "bonus survival": 3]),
    "mountain": (["bonus climb": 4, "bonus endurance": 2]),
    "desert": (["bonus heat resistance": 20])
]));
~~~

##### Trait Persistence and Saving

###### Permanent Trait Storage
Permanent traits are saved with character data:

~~~c
// In character save data
"traits": ([
    "/lib/instances/traits/health/hale.c": ([
        "name": "hale",
        "acquired": time(),
        "bonuses": ({ "bonus constitution", "bonus hit points" })
    ])
])
~~~

###### Temporary Trait Management
Temporary traits are tracked with expiration:

~~~c
// Temporary traits with timers
"temporaryTraits": ({ 
    "/lib/instances/traits/effects/haste.c",
    "/lib/instances/traits/effects/strength.c"
})
~~~

###### Sustained Trait Tracking
Sustained traits are linked to research:

~~~c
// Automatically managed by research system
// No manual persistence required
~~~

##### Reference Summary

###### Core Files
- **lib/modules/traits/baseTrait.c** - Base trait functionality and validation
- **lib/modules/traits.c** - Character trait management and queries
- **lib/services/traitsService.c** - Trait service and caching

###### Trait Instance Directories
- **lib/instances/traits/health/** - Health and wellness traits
- **lib/instances/traits/educational/** - Learning and knowledge traits
- **lib/instances/traits/personality/** - Personality and behavior traits
- **lib/instances/traits/genetic/** - Inherited characteristics
- **lib/instances/traits/effects/** - Temporary magical effects
- **lib/instances/traits/background/** - Cultural and historical traits
- **lib/instances/traits/racial/** - Race-specific abilities
- **lib/instances/traits/biological/** - Biological processes
- **lib/instances/traits/archetypes/** - Personality archetypes

###### Integration Files
- **lib/modules/combat.c** - Combat system integration
- **lib/modules/research.c** - Research system integration
- **lib/services/bonusesService.c** - Bonus validation
- **lib/core/prerequisites.c** - Prerequisite system

##### Trait System Validation

The system validates traits through multiple comprehensive mechanisms:

###### Required Property Validation
All traits must have essential properties:
- name, description, type, root properties must be present
- Valid trait type from validTraitTypes array
- Proper bonus/penalty specifications validated against bonuses service

###### Effect Trait Validation
Effect traits require additional properties:
- duration (for timed effects) must be positive integer
- triggering research (for sustained effects) must be valid research item

###### Bonus System Validation
All bonuses must be validated:

~~~c
object bonusService = getService("bonuses");
bonusService->isValidBonusModifier(bonusToCheck, value);
~~~

###### Conflict Detection
The system prevents conflicting traits:
- Opposing root traits cannot coexist
- Prerequisite validation ensures requirements are met
- Point cost validation maintains character creation balance

This comprehensive traits system provides:
- **Flexibility**: Support for permanent, temporary, and sustained traits
- **Depth**: Complex interactions and synergies between traits
- **Integration**: Seamless connection with combat, research, and social systems
- **Scalability**: Easy addition of new trait types and categories
- **Balance**: Point-based costs and opposing trait mechanics
- **Immersion**: Rich descriptions and meaningful character development

The result is a trait system that enhances character development through
meaningful choices, provides substantial mechanical benefits and penalties,
creates rich roleplaying opportunities, and maintains careful game balance
while allowing for extensive customization and character differentiation.
