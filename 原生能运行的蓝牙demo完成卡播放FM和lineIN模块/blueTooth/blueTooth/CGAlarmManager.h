//
//  CGAlarmManager.h
//  blueTooth
//
//  Created by duluyang on 15/5/23.
//  Copyright (c) 2015年 duluyang. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AlarmEntry;
/*!
 *  @protocol CGAlarmDelegate
 *
 *  @discussion 对象的代理需遵循 <code>CGAlarmDelegate</code>协议.
 */
@protocol CGAlarmDelegate <NSObject>

/*!
 *  @method CGmanagerReady:
 *
 *  @param mode 设备当前的模式
 *
 *  @abstract {@link AlarmManager}对象准备就绪
 *
 *  @seealso  FuncMode
 */
-(void)CGmanagerReady:(UInt32)mode;
/*!
 *  @method CGalarmStateChanged:
 *
 *  @param state 闹铃当前状态
 *
 *  @abstract 闹铃状态变化
 */
- (void)CGalarmStateChanged:(UInt32)state;
/*!
 *  @method CGalarmListArrived:
 *
 *  @param alarmList 音箱闹钟条目列表
 *
 *  @abstract 获取到闹钟条目{@link AlarmEntry}列表对象
 *
 *  @seealso getAlarmList
 */
-(void)CGalarmListArrived:(NSMutableArray*)alarmList;
/*!
 *  @method CGringListArrived:
 *
 *  @param ringList 闹钟铃声条目列表
 *
 *  @abstract 获取到铃声条目{@link RingEntry}列表对象
 *
 *  @seealso getRingList
 */
-(void)CGringListArrived:(NSMutableArray*)ringList;
/*!
 *  @method CGfolderListArrived:
 *
 *  @param folderList 闹钟铃声目录列表
 *
 *  @abstract 获取到铃声目录{@link FolderEntry}列表对象
 *
 *  @seealso getRingFolderList
 */
-(void)CGfolderListArrived:(NSMutableArray*)folderList;

@end

@interface CGAlarmManager : NSObject

/**
 *  设置CGAlarmDelegate代理方法
 *
 *  @param delegate
 */
- (void)setWithCGAlarmDelegate:(id<CGAlarmDelegate>)delegate;

/*!
 *  @method setAlarm:
 *
 *  @param alarm 闹钟条目
 *
 *  @abstract 增加闹钟条目{@link AlarmEntry}或修改音箱上已有的闹钟条目。
 *
 *  @discussion 音箱支持最多设置4条闹钟。
 */
-(void)setAlarm:(AlarmEntry*)alarm;
/*!
 *  @method removeAlarm:
 *
 *  @param alarm 闹钟条目
 *
 *  @abstract 移除音箱上的指定闹钟条目{@link AlarmEntry}。
 */
-(void)removeAlarm:(AlarmEntry*)alarm;
/*!
 *  @method removeAll:
 *
 *  @abstract 移除音箱上所有闹钟条目。
 */
-(void)removeAll;
/*!
 *  @method getAlarmList:
 *
 *  @abstract 获取音箱上已有的闹钟列表。
 *
 *  @seealso alarmListArrived:
 */
-(void)getAlarmList;
/*!
 *  @method getRingList:
 *
 *  @abstract 获取闹钟铃声列表。
 *
 *  @seealso ringListArrived:
 */
-(void)getRingList;
/*!
 *  @method snooze:
 *
 *  @abstract 闹铃贪睡，延时5分钟再起闹。
 */
-(void)snooze;
/*!
 *  @method off:
 *
 *  @abstract 关闭当前闹铃。
 */
-(void)off;
/*!
 *  @method getRingFolderList:
 *
 *  @abstract 获取闹钟铃声目录。
 *
 *  @seealso folderListArrived:
 */
-(void)getRingFolderList;

@end
