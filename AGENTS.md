# Agent Workspace Rules

## Scope

This file is the authoritative instruction entry point for agents working in
this repository. The `.agents/` directory is reserved for agent-only temporary
state, local configuration, isolated Git worktrees, SDD ledgers, review
packages, and migrated historical temporary artifacts. It must not contain
reviewable work products.

## Temporary Work Products

All agent-created temporary artifacts, local Git worktrees, ledgers, review
packages, and migrated historical temporary artifacts belong under `.agents/`.
Do not create new agent temporary content under `work/`, `docs/`, source
directories, or the repository root. `work/` is ignored by Git and is not a
reviewable work-product location.

## Worktree Location

All agent-created Git worktrees must be placed under `.agents/worktrees/`.
This directory is local-only and must remain ignored by Git. The
`.agents/worktrees/` exception does not change the temporary-artifact rule:
these worktrees are local-only and ignored by Git.

## Historical Temporary Artifacts

Migrated historical `docs/superpowers/` temporary artifacts belong under
`.agents/docs/superpowers/`. Do not create new agent temporary content under
`docs/` or any retired legacy path.

## Language Requirements

Repository-facing documentation should match the surrounding content language.
If no language is specified, use Chinese for reader-facing documentation and
English for technical execution details.

## File Conventions

- Use ISO dates in file names: `YYYY-MM-DD-topic-name.md`.
- Keep one document as the canonical source for each deliverable; link to it
  instead of creating copies.
- Use Markdown for text work products unless another format is explicitly
  required.
