##### Commands

This document describes how to author commands by inheriting 
`lib/commands/baseCommand.c`. It explains the parsing lifecycle, target 
resolution, messaging, help generation, and gives properly escaped, inline 
examples for common and advanced commands.

Overview
--------
- Commands are objects that inherit `baseCommand.c`. Implement `SetupCommand()` to register templates and configure the command.
- The dispatcher uses `canExecuteCommand()` (from the base) to detect whether user input matches any registered templates.
- Override `execute(string command, object initiator)` to implement runtime behavior.
- Use `getTarget(...)`, `getTargetString(...)`, and `displayMessage(...)` to resolve targets and present pronoun-aware messages.

Key base features
-----------------
- `addCommandTemplate(string template)` — register usage templates. Templates support optional parts and placeholders like `##Target##`, `##Item##`, `##Value##`.
- `commandRegExp()` / `canExecuteCommand()` — internal template → regex conversion and matching.
- `getTarget(object owner, string command, int flags)` — resolves an object referenced in the command; flags: `TargetInventory`, `TargetEnvironment`, `TargetBoth`.
- `getTargetString(object owner, string command)` — returns the literal portion that matched placeholder (helpful for error messages).
- `parseTemplate(...)`, `displayMessage(...)`, `displayMessageToSelf(...)` — build and broadcast messages with correct pronouns and color preferences.
- Help hooks: override `synopsis`, `description`, `usageDetails`, `flagInformation`, `options`, `notes`.

Formatting note
---------------
All example code blocks in this file are escaped so they can be embedded safely 
in other markdown. Example blocks use the project's C-style command object snippets.

Simple example — say
--------------------
Escaped example for a simple `say` command that broadcasts text to the room:

```
inherit "/lib/commands/baseCommand.c";

public nomask void SetupCommand()
{
    CommandType = "Player Communication";
    addCommandTemplate("say ##Value##");
}

public nomask int execute(string command, object initiator)
{
    if (!canExecuteCommand(command) || !initiator) return 0;

    string text = getTargetString(initiator, command);
    if (!text || text == "")
    {
        displayMessageToSelf("Say what?", initiator);
        return 1;
    }

    displayMessage("##InitiatorName## say##InitiatorReflexive##: \"" + text + "\"",
        initiator, 0);
    return 1;
}
```

Inventory + environment example — give
-------------------------------------
`give <item> to <recipient>`: resolve item from inventory and recipient from room.

```
inherit "/lib/commands/baseCommand.c";

public nomask void SetupCommand()
{
    CommandType = "Player Interaction";
    addCommandTemplate("give ##Item## to ##Target##");
}

public nomask int execute(string command, object initiator)
{
    if (!canExecuteCommand(command)) return 0;

    object item = getTarget(initiator, command, TargetInventory);
    // For recipient, search environment (simplified: parse string and present())
    string recipientStr = getTargetString(initiator, command);
    // naive: strip item part from command to find recipient (real code should parse robustly)
    recipientStr = regreplace(command, "^give .+ to (.+)$", "\\1", 1);
    object recipient = present(lower_case(recipientStr), environment(initiator));

    if (!item)
    {
        displayMessageToSelf("You aren't carrying that.", initiator);
        return 1;
    }
    if (!recipient)
    {
        displayMessageToSelf("They're not here.", initiator);
        return 1;
    }

    item->move(recipient);
    displayMessage("##InitiatorName## give##InitiatorReflexive## "
        "##Target## to ##Target##.", initiator, recipient);
    return 1;
}
```

Selector / UI example — research
-------------------------------
`research.c` demonstrates selector-based UIs: clone a selector, move it to player, register for completion events.

```
inherit "/lib/commands/baseCommand.c";

public nomask void SetupCommand()
{
    CommandType = "Player R&D";
    addCommandTemplate("research");
}

public nomask int execute(string command, object initiator)
{
    if (!canExecuteCommand(command)) return 0;

    object selector = clone_object("/lib/modules/research/researchSelector.c");
    move_object(selector, initiator);
    selector->registerEvent(this_object());
    selector->initiateSelector(initiator);
    return 1;
}

public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}
```

Advanced pattern — options, delayed effects, permissions
-------------------------------------------------------
- Use `flagInformation(...)` and `options(...)` to describe flags.
- For permission checks call the appropriate service (do not directly inspect master state).
- Short-circuitable `call_out` is supported in tests (see test harness). Use `call_out` for delayed actions, but keep logic testable.

```
inherit "/lib/commands/baseCommand.c";

private int beginRitual(object initiator)
{
    if (!getService("security")->canPerform(initiator, "start-ritual"))
    {
        displayMessageToSelf("You are not authorized to do that.", initiator);
        return 0;
    }
    displayMessage("##InitiatorName## begin##InitiatorReflexive## a ritual...", initiator, 0);
    call_out("finishRitual", 3, initiator);
    return 1;
}

private void finishRitual(object initiator)
{
    if (!initiator) return;
    displayMessage("##InitiatorName## complete##InitiatorReflexive## the ritual!", initiator, 0);
}

public nomask void SetupCommand()
{
    CommandType = "Player Action";
    addCommandTemplate("ritual [of] ##Value##");
}

public nomask int execute(string command, object initiator)
{
    if (!canExecuteCommand(command)) return 0;
    string value = getTargetString(initiator, command);
    if (!value || value == "")
    {
        displayMessageToSelf("Ritual of what?", initiator);
        return 1;
    }
    return beginRitual(initiator);
}
```

Help and usage output
--------------------
- The base automatically renders `Syntax` from registered templates. Override `synopsis`, `description`, `options`, `notes` for better help text.
- Use `flagInformation(flag, colorConfiguration)` to document option meanings.

Testing guidance
---------------
- Use `getService(...)` and `users()` wrappers so tests can inject mocks.
- Use `ToggleCallOutBypass()` in `testing.c` to short-circuit `call_out` in unit tests.
- Avoid global state; keep parsing and resolution within the command object for easier unit tests.

Best practices checklist
------------------------
- Register clear templates with `addCommandTemplate`.
- Use `getTarget` and `getTargetString` for robust target resolution.
- Use `displayMessage` / `parseTemplate` for all player-visible messages (ensures pronouns / color are correct).
- Keep parsing and heavy logic separate for easier testing.
- Use services for authorization, persistence, and other side effects.

Where to look
-------------
- `lib/commands/baseCommand.c` — full base implementation.
- `lib/commands/player/say.c`, `lib/commands/player/give.c`, `lib/commands/player/research.c`, `lib/commands/player/map.c` — concrete command examples in the repo.
- `lib/core/messageParser.c` — token replacement used by `parseTemplate`.
- `secure/simulated-efuns/testing.c` — test harness helpers (call_out short-circuit, canned users).
