### Quests

This document describes the quest module: how quests are implemented, how to author them,
the runtime lifecycle, the player-side API, events emitted, and patterns used in the test-suite.
It complements `state-machines.md` by focusing on the quest-specific conventions and services.

Overview
--------
Quests in this mudlib are implemented as state machines that provide:
- a narrative ("journal") per state,
- optional entry/exit events for states,
- transitions driven by events,
- final states marked as `success` or `failure`,
- prerequisite checks before a player may begin a quest,
- a player-side persistence/service layer that tracks which quests are started/active/completed.

Key modules
-----------
- `/lib/modules/quests/questItem.c` — the quest authoring base. Inherits the state machine framework
  and `prerequisites.c`. Used as the base object for every authored quest.
- `/lib/modules/quests.c` — the player-side quests service (API). Tracks quests for a player,
  stores quest metadata (name, current state, completed states, active/completed flags),
  and emits global quest events.
- `/lib/modules/quests/questSelector.c` and `/lib/modules/quests/questSubselector.c` — in-game
  menu/selectors that present the player's quests and details.
- Tests and support objects live under `/lib/tests/support/quests/` (examples: `fakeQuestItem.c`,
  `testKingObject.c`, `mockQuest.c`, `anotherQuest.c`) and demonstrate typical usage.

Authoring a quest
-----------------
Create a new quest by inheriting the quest base:

```
inherit "/lib/modules/quests/questItem.c";

protected void Setup()
{
    setName("The Test of Obedience");
    setType("primary");             // types must exist in the quests service
    setDescription("High-level description for the quests list.");

    addState("entered room", "I entered a strange chamber.");
    addState("starting the test", "I found a rune on the floor.");
    addTransition("entered room", "starting the test", "gotRuneFromFloor");

    addState("resistance rune placed", "I placed a rune and something happened.");
    addTransition("starting the test", "resistance rune placed", "resistanceRunePlaced");
    addEntryAction("resistance rune placed", "spawnUhrdalen");

    addFinalState("uhrdalen left", "failure");
    addTransition("resistance rune placed", "uhrdalen left", "uhrdalenLeft");

    setInitialState("entered room");
}
```

Important methods on `questItem`
- `setName(string)` — set displayed quest name.
- `setDescription(string)` — long description used in the quest list/detail view.
- `setType(string)` — quest type; validated against the quests service types.
- `addState(string name, string description, <optional string entryEvent>, <optional string isFinalState>)` —
  add a state; optional `entryEvent` is broadcast when the state becomes active; `isFinalState` may be
  `"success"` or `"failure"`.
- `addEntryAction(string state, string functionName)` — call this object's method when entering `state`.
  The method is invoked with the actor object as parameter.
- `addExitAction(string state, string functionName)` — call this object's method when exiting `state`.
- `addTransition(string fromState, string toState, string eventName, string initiatorProgram)` —
  connect a transition; `initiatorProgram` optionally restricts who may originate that transition.
- `addFinalState(string state, string result)` — mark state as terminal with result `"success"` or `"failure"`.
- `setInitialState(string)` — set the initial state for the state machine.
- `canBeginQuest(object player)` — uses prerequisites (`prerequisites.c`) to determine eligibility.
- `beginQuest(object player)` — starts the state machine for that player (also called from the player-side service).
- `questStory(string *stateList, object user)` — generate the narrative (journal) from an ordered list of states.

State entry/exit and events
---------------------------
- Entry/exit actions added via `addEntryAction` and `addExitAction` are executed in transitions.
- Entry actions may either call local methods or broadcast events to registered listeners.
- If an entry state was created with an `entryEvent` string, the `registerStateActor` / event-subscription pattern
  allows environments and NPCs to listen and react.
- The quests player service (`/lib/modules/quests.c`) also broadcasts global quest lifecycle events via the
  event module. See "Events emitted" below.

Registering objects controlled by a quest
----------------------------------------
Use `registerStateActor(object actor)` (inherited from the state machine) during `Setup()` or entry actions
to register NPCs, rooms, or items that should receive state events. Registered actors may implement event
handler methods matching the event names you used when adding states (or generic handlers expected by the state
machine/event framework).

Player-side API (service)
-------------------------
The player-side `quests` service (available via `getService("quests")` or methods on the player object)
is the interface used at runtime to manage and query quests for a player. Important behaviors and methods:
- `beginQuest(string questPath)` — start the quest for the player (validates prerequisites).
- `activateQuest(string questPath)` / `deactivateQuest(string questPath)` — mark a started quest active/inactive.
- `advanceQuestState(string questPath, string newState)` — used by questItem to persist a player's new state.
- Query helpers:
  - `questIsActive(questPath)`, `questIsCompleted(questPath)`, `questIsInProgress(questPath)`,
  - `questState(questPath)` — returns the player's current state for that quest,
  - `activeQuests()`, `completedQuests()`, `questsInProgress()` — convenience lists.
- `questStory(questPath)` — returns the narrative assembled from the quest object's state descriptions and
  the player's completed states.

Events emitted
--------------
The quests layer broadcasts global events via the event module (see `/lib/modules/quests.c`). Event names
and when they are fired:
- `onQuestStarted` — fired when a quest is begun for a player.
- `onQuestAdvancedState` — fired whenever the player's quest state advances.
- `onQuestCompleted` — fired when a quest reaches any final state.
- `onQuestSucceeded` / `onQuestFailed` — fired after `onQuestCompleted`, depending on final-state result.
- `onQuestActivated` / `onQuestDeactivated` — fired when manual activation/deactivation occurs.

Event payloads
- The event broadcast uses the quest object's program path (string) as the event value. Subscribers typically
  expect the quest identifier to determine which quest was affected.

Selectors and UI
----------------
- `questSelector.c` and `questSubselector.c` implement the in-game menu for listing and inspecting quests.
  They use the quests service methods:
  - `questTypes()` — types registered in the service (used to build top-level menu),
  - `questsOfType(player, type)` — returns quests (active, completed) for the player grouped by type,
  - `questObject(type)` — returns the quest object for a given type (used to display details when available).
- Subselectors decorate quests with visual markers (active, completed-success, completed-failure). Character
  display preferences (unicode/charset/color) are respected.

Testing patterns
----------------
The tests exercise both the `questItem` behavior and the player-side `quests` service:
- `fakeQuestItem.c` shows a minimal authored quest using `questItem` APIs and helper `test*` wrappers
  used in unit tests.
- `testKingObject.c` and related support objects show how NPCs register for events and cause transitions by
  calling `receiveEvent(questObject, "eventName")` (via the state machine/event framework).
- Tests assert:
  - transitions occur only when expected events fire,
  - entry/exit actions execute and in correct order,
  - prerequisites prevent/allow quest start,
  - final states cause completion and the correct success/failure notifications,
  - the player-side service emits the expected global events.

Best practices
--------------
- Keep state descriptions concise — they are concatenated to create the quest "journal".
- Use `addEntryAction` and `addExitAction` for logic local to the quest object; use `entryEvent` for coupling
  to external objects (rooms, NPCs) via event handlers.
- Final states should not leave long-lived objects registered as state actors; final states are terminal.
- Validate `setType(...)` uses types known to the quests service — this keeps selectors and listing behavior sane.
- Use the tests under `/lib/tests` as examples; they show how to call `beginQuest`, how transitions are triggered,
  and how to observe emitted events.

Quick reference — lifecycle example
-----------------------------------
1. Author quest object by inheriting `questItem.c` and implement `Setup()`:
   - define states, transitions, entry/exit actions, final states, and `setInitialState`.
2. Player begins quest via the quests service:
   - `player->beginQuest("/path/to/quest.c")` or service call `Quests.beginQuest(path)`.
   - quest service creates per-player data: `name`, `state` (initial), `states completed` array, `is active`, `is completed`.
   - `onQuestStarted` event is emitted.
3. Events (e.g., NPC actions) trigger transitions on the quest object; questItem advances its state,
   the player-side service persists the new state and emits `onQuestAdvancedState`.
4. If the new state is final, the service marks the quest completed, emits `onQuestCompleted` and either
   `onQuestSucceeded` or `onQuestFailed`.

See also
--------
- `state-machines.md` — conceptual background and the state machine framework.
- Tests under `/lib/tests/modules/` and `/lib/tests/support/quests/` for concrete examples.
