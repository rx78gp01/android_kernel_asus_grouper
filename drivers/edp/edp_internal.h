/*
 * Copyright (c) 2012, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _EDP_INTERNAL_H
#define _EDP_INTERNAL_H

#include <linux/kernel.h>
#include <linux/edp.h>

struct loan_client {
	struct list_head link;
	struct edp_client *client;
	unsigned int size;
};

static inline unsigned int cur_level(struct edp_client *c)
{
	return c->cur ? *c->cur : 0;
}

static inline unsigned int req_level(struct edp_client *c)
{
	return c->req ? *c->req : 0;
}

static inline unsigned int e0_level(struct edp_client *c)
{
	return c->states[c->e0_index];
}

static inline unsigned int cur_index(struct edp_client *c)
{
	return c->cur ? c->cur - c->states : c->num_states;
}

static inline unsigned int req_index(struct edp_client *c)
{
	return c->req ? c->req - c->states : c->num_states;
}

#endif