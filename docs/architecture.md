# Smart Parking Lot Management System - Architecture

## Goal
Build a C++ parking lot system demonstrating.

## Core Features (Phase 1)
- Park vehicle
- Remove vehicle
- Search vehicle
- Display status

## Data Structure Mapping (Manual)
- Array: fixed slot storage by slotID
- Linked List: free slot tracking (fast add/remove)
- Hash Map: vehicleNumber -> slotID mapping
- Queue: entry order (later)
- Stack: exit history (later)

## Module Responsibilities
- ParkingLot: controller, calls DS modules
- ParkingSlot: slot state
- Vehicle: vehicle info
- LinkedList: manages free slots
- HashMap: fast lookup

## Complexity (High Level)
- Allocation (free slot): O(1) with linked list head
- Lookup (vehicle): avg O(1) hashing
- Remove vehicle: avg O(1) hashing + O(1) list updates
