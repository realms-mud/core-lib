# Creating Monsters

This guide provides a comprehensive overview of how to create monsters in RealmsMUD.
Monsters are highly customizable entities that can range from simple animals to
complex, spellcasting humanoids with unique personalities, equipment, and behaviors.
The system is designed to be flexible, allowing creators to define monsters with a
high degree of detail and realism.

---

## 1. Monster Inheritance and File Structure

All monsters must inherit from one of the realization classes in `/lib/realizations/`.
The choice of base class determines the monster's core behavior and capabilities.

### Common Realization Classes

- `monster.c`: Standard monster logic (most common for enemies).
- `monsterWithAI.c`: Monster with advanced AI and decision-making.
- `npc.c`: Non-player character, often used for townsfolk or quest givers.
- `companion.c`: Follows and assists a player.
- `henchman.c`: Similar to companion, but with more autonomy.
- `wanderingMonster.c`: Roams the world, often used for random encounters and supports autonomous movement.

Example:
~~~
inherit "/lib/realizations/monster.c";
~~~

### Setup Function

Every monster must implement a `Setup()` function. This is where you define
the monster's properties, persona, equipment, and behaviors.

~~~
public void Setup()
{
    // Monster configuration goes here
}
~~~

---

## 2. Monster Creation: Step-by-Step Tutorial

This section walks you through the process of creating a monster, from
basic configuration to advanced customization.

### Step 1: Basic Identity

Set the monster's name, gender, and race. These properties affect how
the monster is displayed and how it interacts with other systems.

~~~
Name("Ralph");
Gender("male");
Race("maegenstryd");
~~~

- `Name(string name)`: Sets the monster's display name.
- `Gender(string gender): Sets gender ("male", "female", "neuter", etc.).
- `Race(string race)`: Sets the monster's race. See `/lib/services/races/races.h` for available races and their effects.

---

### What Does `Race("maegenstryd")` Do?

When you call:
~~~
Race("maegenstryd");
~~~
in your monster's `Setup()` function, you apply the race mapping defined in 
`lib/services/races/races.h`. If you pick "maegenstryd", for example, this
mapping would then get applied to your monster:

~~~
"maegenstryd": ([
    "playable": 1,
    "description": "The Maegenstryd are the descendants of the union of high elves, ...",
    "strength": 1,
    "intelligence": 2,
    "constitution": 2,
    "charisma": 1,
    "hit points": 25,
    "spell points": 15,
    "stamina points": 15,
    "bonus heal hit points rate": 2,
    "research trees": ({ "/lib/instances/research/races/maegenstrydResearchTree.c" }),
    "skills": ([
        "ancient history": 3,
        "spellcraft": 3,
        "magical essence" : 3,
        "perception" : 1,
        "elven": 4,
        "high elven": 4,
        "eledhelean": 8,
        "common": 5
    ]),
    "starting skill points": 8,
    "background trait value": 4
]),
~~~

How the mapping is applied
- Attribute modifiers (`strength`, `intelligence`, etc.) are merged into the monster's attribute table.
- Pool bonuses (`hit points`, `spell points`, `stamina points`) are applied on top of persona/realization defaults and any level scaling.
- `skills` mapping adds starting ranks; persona or explicit adjustments can override later.
- `research trees` registers race-specific research trees with the research system.
- `description` is used for examine text and lore.

Practical guidance
- If you want absolute attribute values, set them after `Race(...)` (e.g., `Intelligence(30);`).
- Race-provided skills and pools are intended as baseline modifiers — persona and explicit overrides refine the final result.
- Use the race `description` verbatim for examine/lore text to remain consistent.

---

### Step 2: Persona System

Personas are archetypes that provide skills, research (spells/abilities), attacks, 
equipment archetypes, and descriptions. Personas live under `lib/services/personas/`
and are applied via the `personas` module.

Call:
~~~
SetUpPersonaOfLevel("oneiromancer", 30);
~~~

What `SetUpPersonaOfLevel(...)` does
- Uses the persona service to validate and apply a persona blueprint.
- Sets the monster's effective level (`effectiveLevel(...)`) accordingly.
- Advances `primary skills` and `secondary skills` to persona-appropriate ranks.
- Adds persona research items (paths) to the monster's `completedResearch()` when level prerequisites are met.
- Configures attacks and persona traits, and contributes description text (if the monster has no custom description).

Persona provides
- Base stats (via persona's SetStats behavior).
- Primary and secondary skills.
- Research items and attack definitions.
- Equipment archetypes for `setUpRandomEquipment()`.

Notes
- Personas can be set only once per living object using `SetUpPersonaOfLevel(...)` (the persona service enforces this).

---

## 3. Equipment Generation

Equipment is created by the persona service and tied to the currently-applied persona.

- `setUpRandomEquipment(int percentChanceOfMagical = 0)`  
  - Implemented in the `personas` module (`lib/modules/personas.c`).
  - Generates, moves, and equips items based on persona and race.
  - Must be called after `SetUpPersonaOfLevel(...)`. If called before, it will raise an error.

If you want manual control:
- Clone or load items and call `Equip(object item)` to equip them programmatically.
- Use `unequip(object item, int silently)` to remove equipment.
- For loot/corpse handling use `transferItemsTo(object destination)` and `transferMoneyFrom(int amount)`.

Inventory & equipment helpers and behaviors are implemented in `lib/modules/inventory.c`. Key capabilities:
- Equipment validation (`isEquipment`) ensures only proper equipment can be worn/wielded.
- `equip(object item)` and `unequip(object item, int silently)` manage slots and cache modifiers.
- The inventory system caches modifiers (resistances, enchantments, material bonuses) and updates on equip/unequip.
- Display helpers like `inventoryText(int verbose, int showMoney)` format inventory for debugging or display.

---

## 4. Spellcasting and Research

Spell-like abilities are implemented as research items. The research system
manages learning, cooldowns, sustained abilities and execution.

Relevant APIs (real code in `lib/modules/research.c` and exposed in the personas module)
- `initiateResearch(string researchPath)` — grant or start learning a research item (pass the research file path/identifier). Use this to add a specific research item to a monster.
- `completedResearch()` — list research items already completed for the monster.
- `researchInProgress()` — list time-based research items currently learning.
- `researchCommand(string command)` — low-level helper to execute a research command (the research service typically routes this).
- `addResearch(string researchPath)` — available via persona module as a convenience to register a research item (aliases to the research machinery).
- `setResearchFrequency(int percentChancePerRound)` (personas module) — configure percent chance per combat round the research execution helper will attempt research.
- `executePersonaResearch(string target, string specificResearch)` (personas module) — helper to request a research attempt. Pass target name and research path or leave research nil to allow the helper to select. The helper respects research frequency and cooldowns.

Practical usage:
~~~
SetUpPersonaOfLevel("aeromancer", 30);
setResearchFrequency(50); // percent per round
initiateResearch("/lib/instances/research/personas/aeromancer/maelstrom.c");
~~~

Notes
- Personas often register many research items automatically; check `completedResearch()` to verify.
- The research module enforces cooldowns, sustained ability costs, and area-of-effect behavior. Use the helpers rather than building raw command strings.

---

## 5. Personality and Traits

Personality is expressed via traits. Traits are located under 
`/lib/instances/traits/` and can modify messaging, AI and behavior.

- `addTrait(string traitPath)` — adds a trait to the monster.
Example:
~~~
addTrait("/lib/instances/traits/personality/haughty.c");
~~~

Traits may:
- Register event handlers.
- Change combat chatter and dialogue.
- Inject AI behavior and state changes.

Conversations:
- Monsters can have conversation scripts or dialogue trees. See `conversations.md` 
for how to author and attach conversation content. Attach via traits or event handlers.

---

## 6. Movement, Wandering and AI

For roaming monsters use `wanderingMonster.c` or `monsterWithAI.c`.

Key APIs in `lib/realizations/wanderingMonster.c` and `pathfinding.c`:
- `enableWandering(int percentChance)` — enable roaming behavior and set default wander percent.
- `setWanderFrequency(int frequency)` — how often (heartbeats) the wander check runs.
- `setWanderChance(int chance)` — percent chance evaluated when the wander check runs.
- `moveInDirection(string direction)` — programmatically move along an exit direction.
- Pathfinding functions are available to construct patrols and route-following behavior.

Wandering details
- The heart_beat loop runs wandering checks at `wanderFrequency` intervals and uses `wanderChance` to determine whether the monster moves.
- `wanderingMonster` avoids wandering while in combat and prevents backtracking where possible.

---

## 7. Combat Integration

Combat is implemented in `lib/modules/combat.c` and tied into living objects 
via `living.c`. Personas populate `getAttacks()`—the combat module reads 
these to perform attacks.

- Persona-provided attacks, breath weapons and research-based attacks integrate with combat heartbeats.
- Use `executePersonaResearch(...)` in custom combat handlers to request research-based attacks (helper respects frequency and cooldowns).
- Inventory and equipment modifiers feed into damage, defend and soak logic via `inventory` module.

### Combat chatter (lib/modules/combatChatter.c)

The combat system calls the combat-chatter helper automatically during 
combat; you do not need to call it in ordinary cases. Add messages during 
setup so the combat path can pick them up and inject them into combat output.

What the system does
- The combat code calls `speakCombatChatter(type, actor, alwaysDisplay)` for appropriate events.
- `speakCombatChatter` picks a random registered message for the given `type` and `state`.
- By default it returns a message rarely (≈1-in-10). `death` and `kill` are always eligible. Pass `alwaysDisplay = 1` to force a return.

How to register messages
- Call the `add*CombatMessage` helpers in `Setup()` (the combat module will read these when appropriate).
  - `addOffensiveHitCombatMessage(string message, string state)`
  - `addDefensiveHitCombatMessage(string message, string state)`
  - `addOffensiveMissCombatMessage(string message, string state)`
  - `addDefensiveMissCombatMessage(string message, string state)`
  - `addDeathMessage(string message, string state)`
  - `addKillMessage(string message, string state)`

Valid `state` values
- For `defensive hit` and `offensive hit` the module supports the actor health-description states (exact strings):
  - `"is knocking on death's door."`
  - `"is severely injured."`
  - `"has taken a beating."`
  - `"has been roughed up."`
  - `"has some minor injuries."`
  - `"is barely inured."`
  - `"is in good shape."`
  - `"any"` — fall-back for any health state
- For `defensive miss`, `offensive miss`, `death`, and `kill` only `"any"` is supported (pass `"any"` or omit the state).

Notes on `state`
- The combat path obtains the actor state via `actor->healthDescription()` and looks up messages registered under that exact string; if none are present it falls back to `"any"`.
- Use the exact strings above when you want messages to appear only at a specific health level; use `"any"` for always-available lines.

Message selection rules
- The module stores multiple messages per type/state and selects one at random.
- Unless `alwaysDisplay` is true, messages are returned infrequently (≈1-in-10). `death` and `kill` bypass that rarity test (are always eligible).

Minimal example (register only; not required to call the chatter manually)
~~~
public void Setup()
{
    SetUpPersonaOfLevel("oneiromancer", 30);

    addOffensiveHitCombatMessage("He laughs as tendrils of dreamlight lash out.", "is in good shape.");
    addOffensiveHitCombatMessage("A surge of dreamlight rends the air.", "any");

    addDefensiveHitCombatMessage("He staggers and grits his teeth.", "has been roughed up.");
    addDeathMessage("He collapses; the dream finally takes him.", "any");
}
~~~

Notes
- Add chatter lines after persona/race are set (so personality and descriptions
  are in place). Combat messages are purely cosmetic but useful for flavor.
- Keep messages short and suitable for insertion into formatted combat lines.
- Use `"any"` as `state` to make a message usable regardless of the actor's health.

---

## 7.1 Factions (lib/modules/factions.c)

The `factions` module manages per-object dispositions and reputations toward
named faction objects exposed by the `factions` service. Monsters can be given
initial reputations, join/leave factions, and have their dispositions evolve
based on `updateFactionDisposition` calls performed by game systems (combat,
quests, AI interactions).

Why use factions for monsters
- Expresses long-term social consequences (merchant friendliness, guards' hostility, etc.).
- Makes NPC/monster behaviour conditional on world social state.
- Integrates with services that gate trading, reputation, and scripted reactions.

Primary public methods (available on living objects)
- `memberOfFaction(string faction)` — returns 1 if the object has joined the faction.
- `Factions()` — returns the list of factions the object is currently a member of.
- `factionDispositionToward(string faction)` — returns the current disposition string for that faction for this object (`"neutral"`, `"ally"`, `"hostile"`, `"betrayed"`, etc. — see the faction service for full mappings).
- `factionReputationToward(string faction)` — integer reputation score tracked for that faction.
- `joinFaction(string faction)` — attempt to join the faction (service validates).
- `leaveFaction(string faction)` — attempt to leave a faction (service validates).
- `updateFactionDisposition(string faction, int reputation, int killedMember)` — adjust reputation and record an interaction; `killedMember` (0/1) affects disposition change logic.

Key behaviours and notes
- Unknown factions are lazily initialized by `isKnownFaction`, which creates the mapping entry and sets default disposition `"neutral"` and initial timestamps.
- `updateFactionDisposition` increments the reputation and number-of-interactions counters, updates timestamps, and calls an internal disposition-change check.
- `checkForDispositionChange` decides whether to change disposition based on:
  - reputation trend over interactions, and
  - time since last disposition (an eight-hour threshold is used: 28800 seconds),
  - or large single events (big reputation swing).
  - If a member was killed (killedMember = 1) it uses `getService("factions")->dispositionFromMurder(...)` to compute a new disposition.
- `joinFaction` and `leaveFaction` both validate via the factions service (`canJoinFaction` / `canLeaveFaction`) before mutating membership. Note: the service currently provides default `canJoinFaction`/`canLeaveFaction` that allow joining/leaving (see TODOs in `lib/services/factionsService.c`).

Example: setting initial faction values or joining in `Setup()`
~~~
public void Setup()
{
    SetUpPersonaOfLevel("merchant", 10);

    // Give an initial positive reputation toward merchants guild
    updateFactionDisposition("/lib/modules/factions/merchantsGuild.c", 200, 0);

    // If you want the monster to be an official member of a faction:
    joinFaction("/lib/modules/factions/merchantsGuild.c");
}
~~~

Typical runtime use
- Combat/AI/quest code should call `updateFactionDisposition(factionPath, delta, killedMemberFlag)`
  when the monster performs actions that affect a faction (helps members, robs, kills a faction member, etc.).
- The faction service may use `getTradingFactions()` to decide which factions to consult for vendor behaviour and negotiation.
- Use `factionDispositionToward()` to gate dialogue, vendor prices, attack/aid logic, or scripted scene content.

Practical tips
- Use absolute faction identifiers (the faction object path) when calling methods.
- Persisted faction entries are stored in the monster's `factions` mapping; initializing values in `Setup()` is appropriate for static starting dispositions.
- Remember `joinFaction`/`leaveFaction` consult service rules — those rules can later be extended to deny joins or require prerequisites.

---

## 8. Skills, Attributes and Other Helpers

- There is no simple public `AddSkill(string,int)` setter on the skills module for adjusting a creature's ranks. Use:
  - `addSkillPoints(int)` to grant points, then
  - `advanceSkill(string skill, int amount)` to raise ranks, or
  - `decrementSkill(string skill, int amount)` to lower ranks and refund points.
- Attribute setters: `Strength(int)`, `Intelligence(int)`, `Dexterity(int)`, etc., are provided by `lib/modules/attributes.c`.
- `effectiveLevel(int)` — get/set the creature's effective level (used by persona and other systems).
- `setMaxHitPoints(int)`, `setMaxSpellPoints(int)`, `setMaxStaminaPoints(int)` — set absolute pool values.

---

## 9. Inventory, Money and Loot

Inventory APIs are implemented in `lib/modules/inventory.c`. Useful methods for monsters:

- `Equip(object item)` — equip an item.
- `unequip(object item, int silently)` — unequip an item.
- `registerObjectAsInventory(object item)` / `unregisterObjectAsInventory(object item)` — register modifier items.
- `Money(int)`, `addMoney(int)`, `transferMoneyFrom(int)` — money management.
- `transferItemsTo(object destination)` — move all items to a destination (use for corpse/loot handling).
- `inventoryText(int verbose, int showMoney)` — formatted inventory view (debugging/display).

Best practices
- When creating loot, use `transferItemsTo(...)` to move items to a corpse or room.
- Use `registerObjectAsInventory(...)` for persistent modifier objects (guild objects, etc.).
- Test `inventoryText(1,1)` to confirm equipped items and modifiers.

---

## 10. Example `Setup()` (complete, realistic)

This sketch shows an idiomatic ordering and real API usage. Note the 
corrected skill-setting approach.

~~~
public void Setup()
{
    Name("Ralph the Oneiromancer");
    Gender("male");

    // Race supplies modifiers and race research tree
    Race("maegenstryd");

    // Persona applies skills, attacks, research and description
    SetUpPersonaOfLevel("oneiromancer", 30);

    // Persona-driven equipment: must be called after persona
    setUpRandomEquipment(80);

    // Grant explicit research (use research file path)
    initiateResearch("/lib/instances/research/personas/oneiromancer/mind-blade.c");
    setResearchFrequency(50);

    // Personality & behavior
    addTrait("/lib/instances/traits/personality/haughty.c");
    enableWandering(30);
    setWanderFrequency(5);

    // Final explicit overrides
    Intelligence(28);

    // Correct way to set a skill rank for a living object:
    addSkillPoints(10);
    advanceSkill("eledhelean", 10);

    // Example faction setup
    updateFactionDisposition("/lib/modules/factions/merchantsGuild.c", 100, 0);
    joinFaction("/lib/modules/factions/merchantsGuild.c");
}
~~~

---

## 11. Troubleshooting & Checklist

- `setUpRandomEquipment()` errors → ensure `SetUpPersonaOfLevel(...)` ran successfully.
- Missing research items → check `completedResearch()` and persona level gating.
- Inventory modifiers absent → validate `Equip(...)` returned true and verify `inventoryText(1,1)`.
- Monster never uses research → verify `setResearchFrequency(...)` > 0 and research items are not on cooldown.
- Combat messages not showing → ensure messages were registered (calls to `add*CombatMessage(...)`)
  and `speakCombatChatter(...)` is called from the combat path with the correct `actor` object.
- Faction updates not taking effect → ensure you use valid faction object paths and call `updateFactionDisposition(...)` or `joinFaction(...)` from game logic that has authority to alter reputations.

---

## 12. Appendix — Skills (Name, Type, Short description)

Below is a compact, copy-ready table containing every skill name, its type,
and a short wrapped description. Columns are aligned for readability. Descriptions
are intentionally short-wrapped to keep lines narrow.

| Skill                      | Type       | Description                                                            |
|---------------------------:|:-----------|:-----------------------------------------------------------------------|
| parry                      | combat     | Use a weapon to block attacks.                                         |
| blind fighting             | combat     | Attack/defend when you cannot see.                                     |
| dodge                      | combat     | Avoid an opponent's attack.                                            |
| dual wield                 | combat     | Attack effectively with an offhand weapon.                             |
| shield                     | combat     | Use shields offensively/defensively (including bladed shields).        |
| axe                        | combat     | Proficiency with one- or two-handed axes.                              |
| long sword                 | combat     | Proficiency with medium-to-large swords (longs, katanas, etc.).        |
| hand and a half sword      | combat     | Proficiency with versatile one-/two-handed swords (bastard, claymore). |
| short sword                | combat     | Proficiency with short blades and cut-down swords.                     |
| dagger                     | combat     | Proficiency with small blades (<18").                                  |
| bow                        | combat     | Proficiency with arm-drawn bows (short/long/composite).                |
| crossbow                   | combat     | Proficiency with mechanically-drawn projectile weapons.                |
| sling                      | combat     | Proficiency with slings and sling-like weapons.                        |
| thrown                     | combat     | Proficiency with thrown weapons (javelins, knives, rocks).             |
| two-handed sword           | combat     | Proficiency with very large two-handed swords (greatswords).           |
| pole arm                   | combat     | Proficiency with polearms (halberd, pike, glaive, etc.).               |
| mace                       | combat     | Proficiency with single-material bludgeoning weapons.                  |
| hammer                     | combat     | Proficiency with war hammers, mauls, and related weapons.              |
| flail                      | combat     | Proficiency with jointed weapons (flails, chains, whips).              |
| staff                      | combat     | Proficiency with staves and blunt polearms.                            |
| plate armor                | combat     | Proficiency with heavy plate-style armors.                             |
| splint armor               | combat     | Proficiency with splint-type armors (metal splints on substrate).      |
| chainmail                  | combat     | Proficiency with interlocking ring armors (chain mail).                |
| scalemail                  | combat     | Proficiency with scale armors (small plates over substrate).           |
| hard leather               | combat     | Proficiency with rigid, treated leather armor (studded options).       |
| soft leather               | combat     | Proficiency with supple leather armor (mobile, light protection).      |
| no armor                   | combat     | Proficiency with padded or cloth armor (robes, everyday clothing).     |
| unarmed                    | combat     | Proficiency in hand-to-hand combat (punch, wrestle, kick).             |
| armorer                    | crafting   | Create armor; higher levels enable exotic materials.                   |
| blacksmithing              | crafting   | Make metal tools, basic components; smelt ores to ingots.              |
| bowyer and fletcher        | crafting   | Create and repair bows and arrows (may need other skills for metal).   |
| carpentry                  | crafting   | Create wooden structures and furniture; engineering for complex builds.|
| dancing                    | crafting   | Perform skilled dancing.                                               |
| acrobatics                 | crafting   | Tumbling and complex corporeal feats.                                  |
| brewing                    | crafting   | Create fermented/distilled liquids and potion-like brews.              |
| gem crafting               | crafting   | Fashion gems and create intricate works.                               |
| leatherworking             | crafting   | Tan leather; make clothing, armor, saddles, packs.                     |
| luthiery                   | crafting   | Build/repair stringed instruments.                                     |
| drum crafting              | crafting   | Build/repair percussive instruments.                                   |
| aerophone crafting         | crafting   | Build/repair woodwind and brass instruments.                           |
| metal crafting             | crafting   | Create metal artworks, ornate weapons and armor.                       |
| mining                     | crafting   | Prospect and extract ores.                                             |
| instrument: plucked        | crafting   | Play and craft plucked string instruments; compose.                    |
| instrument: bowed          | crafting   | Play and craft bowed instruments; compose.                             |
| instrument: woodwind       | crafting   | Play and craft woodwind instruments; compose.                          |
| instrument: brass          | crafting   | Play and craft brass instruments; compose.                             |
| instrument: percussion     | crafting   | Play and craft percussion instruments; compose.                        |
| pottery                    | crafting   | Create pottery and fired clay works.                                   |
| sculpture                  | crafting   | Create artistic sculptures.                                            |
| sewing                     | crafting   | Create garments; embroidery and ornamentation.                         |
| singing                    | crafting   | Perform and compose songs; singing skill.                              |
| stonemasonry               | crafting   | Carve and build with stone; structural work.                           |
| weapon smithing            | crafting   | Create intricate weapons; may require additional skills.               |
| weaving and beadwork       | crafting   | Create textiles, tapestries, beadwork.                                 |
| wood crafting              | crafting   | Create wooden art and goods; higher skill yields finer results.        |
| anatomy and physiology     | erudite    | Anatomy knowledge for healing and surgical/infliction uses.            |
| perception                 | erudite    | Sense deviations and subtle cues; situational awareness.               |
| ancient history            | erudite    | Knowledge of past events, peoples, and civilizations.                  |
| astronomy                  | erudite    | Knowledge of celestial bodies and esoteric celestial lore.             |
| chemistry                  | erudite    | Elemental and compound knowledge; potions and simple compounds.        |
| engineering                | erudite    | Design mechanical constructs, siege gear, locks, mills.                |
| geology                    | erudite    | Knowledge of rocks, soils, and terrain; prospecting.                   |
| herbalism                  | erudite    | Identify and use plants (curative, poisonous, cultivation).            |
| linguistics                | erudite    | Structure of language; accelerates learning similar tongues.           |
| local history              | erudite    | Knowledge of recent/local historical events (scope varies).            |
| mathematics                | erudite    | Arithmetic, geometry, algebra; expands with skill.                     |
| navigation                 | erudite    | Route finding using maps, stars, and natural signs.                    |
| nautical warfare           | erudite    | Command and tactics for ship-based combat.                             |
| overland warfare           | erudite    | Tactics and execution of land-based troop/vehicle combat.              |
| strategy                   | erudite    | Large-scale planning and campaign coordination.                        |
| tactics                    | erudite    | Battlefield maneuvers and unit positioning.                            |
| logistics                  | erudite    | Organizing supply lines, transport, and sustainment.                   |
| philosophy                 | erudite    | Speculative thought; improves debate and oratory.                      |
| physics                    | erudite    | Basic physical laws and mechanics.                                     |
| reading                    | erudite    | Read complex, runic, or scholarly texts.                               |
| spellcraft                 | erudite    | Understand magic systems; craft and defend magical effects.            |
| theology                   | erudite    | Knowledge of gods, rites, and religious practice.                      |
| writing                    | erudite    | Scribing and scholarly composition.                                    |
| zoology                    | erudite    | Understanding animals: habitat, diet, behavior.                        |
| climb                      | subterfuge | Climb difficult surfaces successfully.                                 |
| disable traps              | subterfuge | Disarm or destroy mechanical and constructed traps.                    |
| disguise                   | subterfuge | Non-magically conceal identity or appearance.                          |
| bluff                      | subterfuge | Persuasion through deception.                                          |
| find traps                 | subterfuge | Detect traps and malicious mechanisms.                                 |
| hide                       | subterfuge | Obscure yourself from others' senses.                                  |
| direction sense            | subterfuge | Sense direction and source of stimuli.                                 |
| listen                     | subterfuge | Passive detection and evaluation of sounds.                            |
| move silently              | subterfuge | Move stealthily to avoid detection.                                    |
| open lock                  | subterfuge | Manipulate locking mechanisms and bypass security.                     |
| search                     | subterfuge | Actively seek hidden objects and details.                              |
| set traps and snares       | subterfuge | Construct traps intended to hinder or injure.                          |
| spot                       | subterfuge | Passive detection of unusual sights/movements.                         |
| tracking                   | subterfuge | Trace paths and infer time/actions of tracked creatures.               |
| agriculture                | general    | Basic farming: planting, harvest, animal husbandry.                    |
| animal handling            | general    | Train and control animals; basic commands and handling.                |
| camp skills                | general    | Establish and maintain camps: shelter, fire, provisioning.             |
| cooking                    | general    | Prepare quality food and provisions.                                   |
| etiquette                  | general    | Appropriate conduct and speech in social settings.                     |
| forestry                   | general    | Sustainable logging and tree identification.                           |
| persuasion                 | general    | Convince others via reason or appeal.                                  |
| intimidation               | general    | Coerce or influence via fear or presence.                              |
| barter                     | general    | Negotiate better trade prices when buying or selling.                  |
| diplomacy                  | general    | Work with people sensitively and effectively.                          |
| hunting                    | general    | Hunting, snares, baiting, and related fieldcraft.                      |
| nautical skills            | general    | Basic seamanship and shipboard competency.                             |
| rope skills                | general    | Knotting, rigging, and ropework techniques.                            |
| swimming                   | general    | Proficiency in swimming, including in armor and long distances.        |
| weather sense              | general    | Innate sense of imminent weather changes.                              |
| evocation                  | magic      | Create magical effects (evocation school).                             |
| transformation             | magic      | Change the essence or form of things magically.                        |
| destruction                | magic      | Magic focused on destructive effects.                                  |
| manipulation               | magic      | Bend magical energies to perform acts.                                 |
| divination                 | magic      | Learn/know via magical sensing and insight.                            |
| elemental air              | magic      | Control air-element magical energies.                                  |
| elemental earth            | magic      | Control earth-element magical energies.                                |
| elemental fire             | magic      | Control fire-element magical energies.                                 |
| elemental water            | magic      | Control water-element magical energies.                                |
| magical essence            | magic      | Work with the aetheric/magical substrate.                              |
| mind                       | magic      | Manipulate minds and psionic-like effects.                             |
| senses                     | magic      | Heighten or dull sensory perceptions magically.                        |
| plant                      | magic      | Control plant life and growth.                                         |
| animal                     | magic      | Harness non-sentient creatures via magic.                              |
| body                       | magic      | Affect physical bodies using magical means.                            |
| spirit                     | magic      | Interact with and affect the spirit world.                             |
| blood                      | magic      | Magic tied to living essence and sacrifice.                            |
| dwarven                    | language   | Language of dwarves.                                                   |
| draconid                   | language   | Language of draconids.                                                 |
| high elven                 | language   | Language of the high elves.                                            |
| elven                      | language   | Language of elves.                                                     |
| sylvan                     | language   | Language of woodland creatures.                                        |
| tirnosti                   | language   | Language of Tirnost citizens.                                          |
| eledhelean                 | language   | Language of Eledhel citizens.                                          |
| hillgarathi                | language   | Language of Hillgarath / Lonis Vale.                                   |
| andurathi                  | language   | Language of Andurath citizens.                                         |
| menadrosti                 | language   | Language of Menadrost citizens.                                        |
| endurghul                  | language   | Language of Endurghul and western regions.                             |
| orcish                     | language   | Language of orcs and many 'dark' creatures.                            |
| common                     | language   | The common lingua franca.                                              |

---

## 13. Final Notes & Best Practices

- Start with `Race(...)` + `SetUpPersonaOfLevel(...)` as your canonical baseline.
- Call `setUpRandomEquipment()` only after persona is set.
- Register research items by their research file paths and use `executePersonaResearch()` to attempt research in combat.
- Use `addSkillPoints()` + `advanceSkill()` for setting skill ranks programmatically.
- Add traits for personality and conversation hooks; for conversation authoring see `conversations.md`.
- Test monsters in-game to verify merged values produce the intended result.
